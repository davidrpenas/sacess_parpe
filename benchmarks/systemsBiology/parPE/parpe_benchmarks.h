#ifndef PARPE_BENCH

#define PARPE_BENCH

#include <float.h>

extern char *output_h5;

#ifdef Boehm
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Borghans
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Blasi
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Crauste
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Elowitz
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Fujita
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Alkan
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Bruno
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif


#ifdef Chen
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Giordano
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Beer
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Bertozzi
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Isensee
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Laske
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Lucarelli
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Okuonghae
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Oliveira
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Perelson
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Rahman
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Raimundez
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef SalazarCavazos
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Sneyd
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Weber
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Zheng
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Schwen
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Fiedler
    #include "LS.h"
    #include "cost_function.h"
    extern const char *string_h5_forward;
    extern const char *string_h5_adjoint;
    extern const char* return_benchmark ;
    extern const int parpe_type ;
    extern const double parpe_VTR_default ;
    extern const double parpe_jf ;
#endif

#ifdef Zhao
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Armistead
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Raia
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Smith
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Bachmann
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Lang
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Froehlich
    #include "LS.h"
	#include "cost_function.h"
     extern const char *string_h5_forward;
     extern const char *string_h5_adjoint;
	 extern const char* return_benchmark ;
	 extern const int parpe_type ;
	 extern const double parpe_VTR_default ;
	 extern const double parpe_jf ;
#endif

#ifdef Brannmark
    #include "LS.h"
    #include "cost_function.h"
       extern const char *string_h5_forward;
       extern const char *string_h5_adjoint;
       extern const char* return_benchmark ;
       extern const int parpe_type ;
       extern const double parpe_VTR_default ;
       extern const double parpe_jf ;
#endif


#endif
