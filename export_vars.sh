# Example of export variable to load prev to installation or runnning
# Example for supercomputer CESGA

module load gcc/system gcccore/12.3.0 python/3.10.8 openmpi/4.0.5_ft3 boost/1.83.0  cmake/3.23.1 imkl

export PARPE_NO_DEBUG=1
export LD_PRELOAD=/opt/cesga/2020/software/Core/imkl/2021.3.0/lib/intel64/libmkl_core.so:/opt/cesga/2020/software/Core/imkl/2021.3.0/lib/intel64/libmkl_sequential.so
export PKG_CONFIG_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/ThirdParty/Ipopt-releases-3.13.3/install/lib/pkgconfig:$PKG_CONFIG_PATH
export CMAKE_PREFIX_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/ThirdParty/Ipopt-releases-3.13.3/install:$CMAKE_PREFIX_PATH
export LD_LIBRARY_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/ThirdParty/Ipopt-releases-3.13.3/install/lib:$LD_LIBRARY_PATH
export PKG_CONFIG_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/ThirdParty/Ipopt-releases-3.13.3/ThirdParty-HSL/install/lib/pkgconfig:$PKG_CONFIG_PATH
export PKG_CONFIG_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/ThirdParty/Ipopt-releases-3.13.3/install/lib/pkgconfig:$PKG_CONFIG_PATH
export PKG_CONFIG_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/ThirdParty/Ipopt-releases-3.13.3/install/lib64/pkgconfig:$PKG_CONFIG_PATH

export CMAKE_INCLUDE_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/include:$CMAKE_INCLUDE_PATH
export PARPE_NUM_SIMULATION_TRIALS=1
export OMP_NUM_THREADS=1
export ParPE_DIR=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/build
export Amici_DIR=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/deps/AMICI/build

export CPATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/include:$CPATH
export CPATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/deps/AMICI/include:$CPATH
export CPATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/build/src:$CPATH

export CC=/opt/cesga/2020/software/Core/gcccore/12.3.0/bin/gcc
export CXX=/opt/cesga/2020/software/Core/gcccore/12.3.0/bin/g++
export CXXFLAGS="-std=c++11 -static-libstdc++"






module load gcc/system gcccore/12.3.0 python/3.10.8 openmpi/4.0.5_ft3 boost/1.83.0  cmake/3.23.1 imkl
export PARPE_NO_DEBUG=1
export PARPE_NUM_SIMULATION_TRIALS=1
export OMP_NUM_THREADS=1
export ParPE_DIR=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/build
export Amici_DIR=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/deps/AMICI/build
export CMAKE_PREFIX_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/ThirdParty/Ipopt-releases-3.13.3/install:$CMAKE_PREFIX_PATH
export PKG_CONFIG_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/ThirdParty/Ipopt-releases-3.13.3/ThirdParty-HSL/install/lib/pkgconfig:$PKG_CONFIG_PATH

