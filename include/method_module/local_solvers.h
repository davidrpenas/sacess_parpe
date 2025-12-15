#include <structure_paralleltestbed.h>


void callnl2sol_(void *, void *(*fitnessfunction)(double*, void*),double *, long *, long *, long *, int *, int *);

void NL2SOL_pe(double *, int , long *, void *, long , long *, int * );
		 
int calcr_(int *, int *, double *, int *, double *, int *, double *, void* , int *, int *);
		
int calcj_(int *, int* , double *, int *, double *, int *, double *, void*, int *, int *);

