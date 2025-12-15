#ifdef MATLAB
#ifdef GNU

#include <structure_paralleltestbed.h>
#include <examplematlab.h>


void* examplefunctionmatlab(double *x, void *data) {
    experiment_total *exp1;
    output_function *res;
    outputmatlab *omt;
    double y, resultado;
    double *residuo;
    double *g; 
    int i,D,error,size_r,size_g;
    int option;
    const char *matlabMINLP, *matlabNLP, *matlabPE;
    matlabPE    = "matlabPE";
    matlabNLP   = "matlabNLP";
    matlabMINLP = "matlabMINLP";
    exp1 = (experiment_total *) data;

    if (strcmp((*exp1).test.bench.type, matlabMINLP) == 0) option=2;
    else if  (strcmp((*exp1).test.bench.type, matlabNLP) == 0) option=1;
    else if  (strcmp((*exp1).test.bench.type, matlabPE) == 0) option=0;

    D=(*exp1).test.bench.dim; // DIMENSION OF THE PROBLEM
    res = NULL;
    res = (output_function *) calloc(1,sizeof(output_function));
    omt = (outputmatlab *) malloc(sizeof(outputmatlab));  
    omt->size_residual = 0;
    omt->size_penalty  = 0; 
#ifdef GNU
    __matlabproblem_MOD_matlabobjfunc(x,&D,&resultado,omt,&exp1->execution.ep_matlab,&option);
#elif defined(INTEL)
    matlabproblem_mp_matlabobjfunc_(x,&D,&resultado,omt,&exp1->execution.ep_matlab,&option);
#endif
    res->value = resultado;

    if ( omt->size_penalty > 0 ) {
	res->g = (double *) malloc( omt->size_penalty  * sizeof(double));
	for (i=0;i<omt->size_penalty;i++) {
		res->g[i]=omt->penalty[i];
    	}
	res->size_g=omt->size_penalty;	
    }

    if ( omt->size_residual > 0) {
	res->R = (double *) malloc( omt->size_residual * sizeof(double));
	for (i=0;i<res->size_r;i++) res->R[i] = omt->residual[i];
	res->size_r=omt->size_residual;
    }

    free(omt);

    return res;
}




#endif
#endif

