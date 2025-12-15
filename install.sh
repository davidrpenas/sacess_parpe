export PARPE_NO_DEBUG=1
export PARPE_NUM_SIMULATION_TRIALS=1
export OMP_NUM_THREADS=1
export OMPI_CC=gcc
export OMPI_CXX=g++
export OMPI_FC=gfortran
export CC=mpicc
export CXX=mpic++
export FC=mpifort

rm -Rf build
rm -Rf deps/AMICI/build
sed -i 's|^\("${parpe_root}/ThirdParty/installCeres.sh"\)|#\1|' buildAll.sh
sed -i 's|^\("${parpe_root}/ThirdParty/installIpopt.sh"\)|#\1|' buildAll.sh

sed -i 's|^#\(scripts/buildAll.sh\)|\1|' buildAll.sh
sed -i 's/cmake "${parpe_root}"/cmake "${parpe_root}" -DPARPE_ENABLE_MPI=FALSE  -DPARPE_ENABLE_CERES=FALSE/' ./buildAll.sh
sed -i 's/class LoadBalancerMaster;/#ifdef PARPE_ENABLE_MPI\nclass LoadBalancerMaster;\n#else\nusing LoadBalancerMaster = int;\n#endif/' ./include/parpeamici/multiConditionProblem.h
sed -i '/^#include <parpeamici\/amiciMisc.h>/a #include <parpecommon/logging.h>' ./src/parpeamici/optimizationApplication.cpp
sed -i 's/logmessage(LOGLVL_INFO/logmessage(loglevel::info/g; s/saveTotalCpuTime(file_id/saveTotalCpuTime(h5File/g' ./src/parpeamici/optimizationApplication.cpp

./buildAll.sh
