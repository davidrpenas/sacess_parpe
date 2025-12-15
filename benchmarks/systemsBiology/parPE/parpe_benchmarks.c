#include "parpe_benchmarks.h"

#include <float.h>

char *output_h5 = "";

#ifdef Boehm
     const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Boehm_JProteomeRes2014/Boehm_JProteomeRes2014_forward.h5";
	 const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Boehm_JProteomeRes2014/Boehm_JProteomeRes2014_adjoint.h5";
	 const char* return_benchmark = "Boehm_JProteomeRes2014";
	 const int parpe_type = 0;
	 const double parpe_VTR_default = -DBL_MIN;
	 const double parpe_jf =  138.221997;
							  
#endif

#ifdef Borghans
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Borghans_BiophysChem1997/Borghans_BiophysChem1997_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Borghans_BiophysChem1997/Borghans_BiophysChem1997_adjoint.h5";		 
	 const char* return_benchmark = "Borghans_BiophysChem1997";
	 const int parpe_type = 1;
	 const double parpe_VTR_default = -DBL_MIN;
	 const double parpe_jf =  -83.323673;
#endif

#ifdef Blasi
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Blasi_CellSystems2016/Blasi_CellSystems2016_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Blasi_CellSystems2016/Blasi_CellSystems2016_adjoint.h5";
	 const char* return_benchmark = "Blasi_CellSystems2016";
	 const int parpe_type = 2;
	 const double parpe_VTR_default = -DBL_MIN;
	 const double parpe_jf =  -642.826601;
#endif

#ifdef Crauste
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Crauste_CellSystems2017/Crauste_CellSystems2017_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Crauste_CellSystems2017/Crauste_CellSystems2017_adjoint.h5";
		 const char* return_benchmark = "Crauste_CellSystems2017";
		 const int parpe_type = 3;
		 const double parpe_VTR_default = -DBL_MIN;
		 const double parpe_jf =  191.097833;
#endif

#ifdef Elowitz
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Elowitz_Nature2000/Elowitz_Nature2000_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Elowitz_Nature2000/Elowitz_Nature2000_adjoint.h5";
		 const char* return_benchmark = "Elowitz_Nature2000";
		 const int parpe_type = 4;
		 const double parpe_VTR_default = -DBL_MIN;
		 const double parpe_jf =  -63.202804;
#endif

#ifdef Fujita
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Fujita_SciSignal2010/Fujita_SciSignal2010_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Fujita_SciSignal2010/Fujita_SciSignal2010_adjoint.h5";
		 const char* return_benchmark = "Fujita_SciSignal2010";
		 const int parpe_type = 5;
		 const double parpe_VTR_default = -DBL_MIN;
		 const double parpe_jf =   -53.087482;
#endif

#ifdef Alkan
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Alkan_SciSignal2018/Alkan_SciSignal2018_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Alkan_SciSignal2018/Alkan_SciSignal2018_adjoint.h5";
		 const char* return_benchmark = "Alkan_SciSignal2018";
		 const int parpe_type = 6;
		 const double parpe_VTR_default = -DBL_MIN;
		 const double parpe_jf =  281376580.325973;
#endif

#ifdef Bruno
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Bruno_JExpBot2016/Bruno_JExpBot2016_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Bruno_JExpBot2016/Bruno_JExpBot2016_adjoint.h5";		 
		 const char* return_benchmark = "Bruno_JExpBio2016";
		 const int parpe_type = 7;
		 const double parpe_VTR_default = -DBL_MIN;
		 const double parpe_jf =   -46.688153;
#endif


#ifdef Chen
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Chen_MSB2009/Chen_MSB2009_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Chen_MSB2009/Chen_MSB2009_adjoint.h5";		 
		 const char* return_benchmark = "Chen_MSB2009";
		 const int parpe_type = 8;
		 const double parpe_VTR_default = -DBL_MIN;
		 const double parpe_jf =  130591.726221;
#endif

#ifdef Giordano
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Giordano_Nature2020/Giordano_Nature2020_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Giordano_Nature2020/Giordano_Nature2020_adjoint.h5";		 
		 const char* return_benchmark = "Giordano_Nature2020";
		 const int parpe_type = 9;
		 const double parpe_VTR_default =  -DBL_MIN;
		 const double parpe_jf =  287.627761;
#endif

#ifdef Beer
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Beer_MolBioSystems2014/Beer_MolBioSystems2014_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Beer_MolBioSystems2014/Beer_MolBioSystems2014_adjoint.h5";		 
		 const char* return_benchmark = "Beer_MolBioSystems2014";
		 const int parpe_type = 10;
		 const double parpe_VTR_default =  -DBL_MIN;
		 const double parpe_jf =   -DBL_MIN;
#endif

#ifdef Bertozzi
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Bertozzi_PNAS2020/Bertozzi_PNAS2020_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Bertozzi_PNAS2020/Bertozzi_PNAS2020_adjoint.h5";		 
		 const char* return_benchmark = "Bertozzi_PNAS2020";
		 const int parpe_type = 11;
		 const double parpe_VTR_default =  -DBL_MIN;
		 const double parpe_jf =   -DBL_MIN;
#endif


#ifdef Brannmark 
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Brannmark_JBC2010/Brannmark_JBC2010_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Brannmark_JBC2010/Brannmark_JBC2010_adjoint.h5";		
         const char* return_benchmark = "Brannmark_JBC2010";
         const int parpe_type = 12;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -DBL_MIN;
#endif

#ifdef Fiedler
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Fiedler_BMCSystBiol2016/Fiedler_BMCSystBiol2016_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Fiedler_BMCSystBiol2016/Fiedler_BMCSystBiol2016_adjoint.h5";
         const char* return_benchmark = "Fiedler_BMC2016";
         const int parpe_type = 13;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -DBL_MIN;
#endif

#ifdef Isensee
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Isensee_JCB2018/Isensee_JCB2018_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Isensee_JCB2018/Isensee_JCB2018_adjoint.h5";	
         const char* return_benchmark = "Isensee_JCB2018";
         const int parpe_type = 14;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -DBL_MIN;
#endif

#ifdef Laske
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Laske_PLOSComputBiol2019/Laske_PLOSComputBiol2019_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Laske_PLOSComputBiol2019/Laske_PLOSComputBiol2019_adjoint.h5";	
         const char* return_benchmark = "Laske_PLOSComputBiol2019";
         const int parpe_type = 15;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -DBL_MIN;
#endif

#ifdef Lucarelli
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Lucarelli_CellSystems2018/Lucarelli_CellSystems2018_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Lucarelli_CellSystems2018/Lucarelli_CellSystems2018_adjoint.h5";	
         const char* return_benchmark = "Lucarelli_CellSystems2018";
         const int parpe_type = 16;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -DBL_MIN;
#endif

#ifdef Okuonghae
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Okuonghae_ChaosSolitonsFractals2020/Okuonghae_ChaosSolitonsFractals2020_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Okuonghae_ChaosSolitonsFractals2020/Okuonghae_ChaosSolitonsFractals2020_adjoint.h5";	
         const char* return_benchmark = "Okuonghae_ChaosSolitonsFractals2020";
         const int parpe_type = 17;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -DBL_MIN;
#endif

#ifdef Oliveira
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Oliveira_NatCommun2021/Oliveira_NatCommun2021_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Oliveira_NatCommun2021/Oliveira_NatCommun2021_adjoint.h5";	
         const char* return_benchmark = "Oliveira_NatCommun2021";
         const int parpe_type = 18;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -DBL_MIN;
#endif

#ifdef Perelson
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Perelson_Science1996/Perelson_Science1996_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Perelson_Science1996/Perelson_Science1996_adjoint.h5";	
         const char* return_benchmark = "Perelson_Science1996";
         const int parpe_type = 19;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -DBL_MIN;
#endif

#ifdef Rahman
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Rahman_MBS2016/Rahman_MBS2016_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Rahman_MBS2016/Rahman_MBS2016_adjoint.h5";			 
         const char* return_benchmark = "Rahman_MBS2016";
         const int parpe_type = 20;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -DBL_MIN;
#endif

#ifdef Raimundez
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Raimundez_PCB2020/Raimundez_PCB2020_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Raimundez_PCB2020/Raimundez_PCB2020_adjoint.h5";			 
         const char* return_benchmark = "Raimundez_PCB2020";
         const int parpe_type = 21;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -DBL_MIN;
#endif

#ifdef SalazarCavazos
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_SalazarCavazos_MBoC2020/SalazarCavazos_MBoC2020_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_SalazarCavazos_MBoC2020/SalazarCavazos_MBoC2020_adjoint.h5";			 
         const char* return_benchmark = "SalazarCavazos";
         const int parpe_type = 22;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -DBL_MIN;
#endif


#ifdef Sneyd
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Sneyd_PNAS2002/Sneyd_PNAS2002_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Sneyd_PNAS2002/Sneyd_PNAS2002_adjoint.h5";		
                 const char* return_benchmark = "Sneyd_PNAS2002";
                 const int parpe_type = 23;
                 const double parpe_VTR_default = -DBL_MIN;
                 const double parpe_jf =  -319.791851;
#endif

#ifdef Weber
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Weber_BMC2015/Weber_BMC2015_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Weber_BMC2015/Weber_BMC2015_adjoint.h5";		
         const char* return_benchmark = "Weber_BMC2015";
         const int  parpe_type = 24;
         const double parpe_VTR_default = -DBL_MIN;
         const double parpe_jf =   296.201763;
#endif

#ifdef Zheng
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Zheng_PNAS2012/Zheng_PNAS2012_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Zheng_PNAS2012/Zheng_PNAS2012_adjoint.h5";		
         const char* return_benchmark = "Zheng_PNAS2012";
         const int parpe_type = 25;
         const double parpe_VTR_default = -DBL_MIN;
         const double parpe_jf =   -278.333648;
#endif

#ifdef Schwen
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Schwen_PONE2014/Schwen_PONE2014_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Schwen_PONE2014/Schwen_PONE2014_adjoint.h5";	
         const char* return_benchmark = "Schwen_PONE2014";
         const int parpe_type = 26;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =  956.518436;
#endif

#ifdef Zhao
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Zhao_QuantBiol2020/Zhao_QuantBiol2020_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Zhao_QuantBiol2020/Zhao_QuantBiol2020_adjoint.h5";			 
         const char* return_benchmark = "Zhao_QuantBiol2020";
         const int parpe_type = 27;
         const double parpe_VTR_default =  777.344265;
         const double parpe_jf =   -DBL_MIN;
#endif

#ifdef Armistead
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Armistead_CellDeathDis2024/Armistead_CellDeathDis2024_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Armistead_CellDeathDis2024/Armistead_CellDeathDis2024_adjoint.h5";			 
         const char* return_benchmark = "Armistead_CellDeathDis2024";
         const int parpe_type = 28;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   -301.916182;
#endif

#ifdef Raia
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Raia_CancerResearch2011/Raia_CancerResearch2011_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Raia_CancerResearch2011/Raia_CancerResearch2011_adjoint.h5";			 
         const char* return_benchmark = "Raia_CancerResearch2011";
         const int parpe_type = 29;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   346.089786;
#endif

#ifdef Smith
		 const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Smith_BMCSystBiol2013/Smith_BMCSystBiol2013_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Smith_BMCSystBiol2013/Smith_BMCSystBiol2013_adjoint.h5";			 
         const char* return_benchmark = "Smith_BMCSystBiol2013";
         const int parpe_type = 30;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =   888198.435649;
#endif

#ifdef Bachmann
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Bachmann_MSB2011/Bachmann_MSB2011_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Bachmann_MSB2011/Bachmann_MSB2011_adjoint.h5";
         const char* return_benchmark = "Bachmann_MSB2011";
         const int parpe_type = 31;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =  -419.129483;
#endif

#ifdef Lang
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Bachmann_MSB2011/Lang_PLOSComputBiol2024.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Bachmann_MSB2011/Lang_PLOSComputBiol2024.h5";
         const char* return_benchmark = "Lang_PLOSComputBiol2024";
         const int parpe_type = 32;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =  -DBL_MIN;
#endif

#ifdef Froehlich
         const char *string_h5_forward = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Froehlich_CellSystems2018/Froehlich_CellSystems2018_forward.h5";
         const char *string_h5_adjoint = "/opt/sacess_petab/benchmarks/systemsBiology/parPE/parpe_Froehlich_CellSystems2018/Froehlich_CellSystems2018_adjoint.h5";
         const char* return_benchmark = "Froehlich_CellSystems2018";
         const int parpe_type = 33;
         const double parpe_VTR_default =  -DBL_MIN;
         const double parpe_jf =  -DBL_MIN;
#endif
