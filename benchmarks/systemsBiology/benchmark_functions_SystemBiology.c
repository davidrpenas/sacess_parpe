#include <stdlib.h>
#include <string.h>
#include <structure_paralleltestbed.h>
#include <common_solver_operations.h>
#include <configuration.h>
#include <math.h>
#include <input_module.h>
#include <def_errors.h>
#include <float.h>
#include "parpe_benchmarks.h"
#include <stdio.h>
#include <time.h>

#include <hdf5.h>

#define PI (3.141592653589793238462643383279)


int load_benchmark_test(experiment_total *exp, double *target, double *ftarget) {
    int D,i;
    double Up, Lo;
    
    
    D = (*exp).test.bench.dim;
    
    Up = exp->test.bench.max_dom[0]; 
    Lo = exp->test.bench.min_dom[0];
    
    exp->test.bench.max_dom = (double *) malloc(D* sizeof (double) );
    exp->test.bench.min_dom = (double *) malloc(D* sizeof (double) );
    
    for (i=0;i<D;i++) {
                exp->test.bench.max_dom[i] = Up;
                exp->test.bench.min_dom[i] = Lo;
    }
    
    *target = -100000;        
    *ftarget = -100000;
    
    return 1;
}


const char* return_benchmark_SystemBiology(int i) {
   
    	return return_benchmark;
}

char * getnameSB(int id){
    char * name;

    name = (char) calloc(500,sizeof(char) );

    name = return_benchmark;

    return name;
}


void load_Bound_to_structure(const char *filename, double *bound, const char *dataset, size_t dim) {
    hid_t file_id, dataset_id, dataspace_id; // Identifiers for the file, dataset, and dataspace
    herr_t status;
    hsize_t dims[1]; // Dimensions of the dataset

    // Open the HDF5 file
    file_id = H5Fopen(filename, H5F_ACC_RDONLY, H5P_DEFAULT);
    if (file_id < 0) {
        fprintf(stderr, "Error opening the HDF5 file\n");
        return;
    }

    // Open the dataset `/parameters/upperBound`
    dataset_id = H5Dopen2(file_id, dataset, H5P_DEFAULT);
    if (dataset_id < 0) {
        fprintf(stderr, "Error opening the dataset /parameters/upperBound\n");
        H5Fclose(file_id);
        return;
    }

    // Get the dataspace of the dataset to check dimensions
    dataspace_id = H5Dget_space(dataset_id);
    H5Sget_simple_extent_dims(dataspace_id, dims, NULL);

    // Check if the dimensions match the expected size
    if (dims[0] != dim) {
        fprintf(stderr, "Dataset dimensions (%llu) do not match the expected size (%lu)\n", 
                (unsigned long long)dims[0], dim);
        H5Sclose(dataspace_id);
        H5Dclose(dataset_id);
        H5Fclose(file_id);
        return;
    }

    // Read the data from the dataset into the array
    status = H5Dread(dataset_id, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, bound);
    if (status < 0) {
        fprintf(stderr, "Error reading the dataset\n");
        free(bound);
        bound = NULL;
    }

    // Close all opened resources
    H5Sclose(dataspace_id);
    H5Dclose(dataset_id);
    H5Fclose(file_id);
}


int load_benchmark_SystemBiology(experiment_total *exp) {
    const char *path;
    int i,j;
    int type;
    int amigo_flag;
    int counter, exito, init_cond;
    double point;
    int *index_non_obs;
	const char *string_h5;

    type = -1;
    amigo_flag=0;
   
    (*exp).test.bench.estime_init_cond = 0; 
   
    // PARPE PROBLEMS
    type = parpe_type;
    (*exp).test.VTR_default = parpe_VTR_default;
    (*exp).test.jf = parpe_jf;
	

    if ((*exp).test.amici_sensi == 1) string_h5 = string_h5_forward;
    else if ((*exp).test.amici_sensi == 2) string_h5 = string_h5_adjoint;
    else string_h5 = string_h5_adjoint;
	
	load_proplem(string_h5);
	
	if ((*exp).test.bench.max_dom == NULL) {
		(*exp).test.bench.max_dom = (double *) malloc((*exp).test.bench.dim* sizeof (double) );
		(*exp).test.bench.min_dom = (double *) malloc((*exp).test.bench.dim* sizeof (double) );
		
		
		load_Bound_to_structure(string_h5, (*exp).test.bench.max_dom, "/parameters/upperBound", (*exp).test.bench.dim);
		load_Bound_to_structure(string_h5, (*exp).test.bench.min_dom, "/parameters/lowerBound", (*exp).test.bench.dim);

	}

    exp->test.bench.use_amigo=amigo_flag;
    exp->test.bench.idtype=type; 
    exp->param = NULL;
		
    return 1;
    
}



/*
void manage_init_cond(experiment_total *exp,double *U, double *U_aux) {
    int n_IC, counter;
    int i, j, exito, *index_non_obs;
    
    n_IC = exp->amigo->amigo_models[0]->n_states - exp->amigo->amigo_models[0]->n_observables;
    index_non_obs = (int *) malloc(n_IC * sizeof (int));
    counter = 0;
    for (i = 0; i < exp->amigo->amigo_models[0]->n_states; i++) {
        exito = 0;
        for (j = 0; j < exp->amigo->amigo_models[0]->n_observables; j++) {
            if (exp->amigo->amigo_models[0]->index_observables[j] == i) {
                exito = 1;
                break;
            }
        }
        if (exito == 0) {
            index_non_obs[counter] = i;
            counter++;
        }
    }

    for (i=0;i<exp->amigo->n_exp;i++){
        for (j=0;j<n_IC;j++) {
            exp->amigo->amigo_models[i]->y0[index_non_obs[j]]=U[j];
        }
    }
    
    
    
    counter=0;
    for (i=n_IC;i<exp->test.bench.dim;i++){
        U_aux[counter]=U[i];
        counter++;
    }    
}


void repack_init_cond(experiment_total *exp,double *U, double *U_aux) {
    int n_IC,i,max,counter;
    
    n_IC = exp->amigo->amigo_models[0]->n_states - exp->amigo->amigo_models[0]->n_observables;
    max = exp->test.bench.dim;
    counter=0;
    for (i=n_IC; i<max ;i++){
        U[i]=U_aux[counter];
        counter++;
    }        
}


int destroySystemBiology(experiment_total *exp) {

    if (exp->amigo != NULL) {
        free_AMIGO_problem(exp->amigo);
        exp->amigo=NULL;
    }
    free(exp->execution.transconst);
    free(exp->test.bench.logindex);
    free(exp->test.bench.log_max_dom );
    free(exp->test.bench.log_min_dom );


    return 1;

}

*/
void* cost_eval_petab(double *U, void* data) {
    output_function *res;
    experiment_total *exp1;

    
    exp1 = (experiment_total *) data;
    res = NULL;
    res = (output_function *) calloc(1,sizeof(output_function));
    res->size_gradient = (int) (*exp1).test.bench.dim;
   
    double fvalue;
    double *gradient = (double *) calloc(res->size_gradient,sizeof(double) );
    double *residual;
    int size_residual;

    eval_cost(U, &fvalue, &residual, &size_residual, gradient );

    res->gradient = gradient;
    res->value = fvalue;
    res->size_r = size_residual;
    res->R = residual;

    return ((void *) res);

}


void* evalSB_(double *U, void* data) {
    setenv("PARPE_OPTION_SOLVE","1",1);
    setenv("PARPE_LOG_SIMULATIONS","0",1);
    setenv("PARPE_NO_DEBUG","1",1);
    setenv("PARPE_NUM_SIMULATION_TRIALS","1",1);
    return cost_eval_petab(U, data);
}


void* evalSB_residuals(double *U, void* data) {

    setenv("PARPE_OPTION_SOLVE","2",1);
    return cost_eval_petab(U, data);

}


