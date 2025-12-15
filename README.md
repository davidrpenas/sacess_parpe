# SaCeSS+PETab

## An modified version of SaCeSS to work with problems in PETab format. 

This is an initial integration between SaCeSS solver and PETab file problems. The next notes refer to how to compile and use it.

## Installation

First, install parPE because it is the place where we extract the cost function implemented in C. You should install the PARPE located in the sacess+parpe repository, because it has modifications required to integrate SaCeSS with PEtabbenchmarks.
	 	
Once you have installed it, modify the SaCeSS "Makefile" with the parPE directories. In my case:
	
...
PATHPARPE=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE
PATHHDF5=/opt/cesga/easybuild-cesga/software/MPI/gcc/6.4.0/openmpi/2.1.1/hdf5/1.10.3
PATHBOOST=/mnt/netapp1/Optcesga_FT2_RHEL7/easybuild-cesga/software/MPI/gcc/6.4.0/openmpi/2.1.1/boost/1.74.0-python-3.8.1
PATHIPOPT=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/install
PATHCERES=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/ceres-solver-2.0.0/build/install
...

In our case, we also need to call the followings software modules previous to call Makefile. Our supercomputer use a module software system to manage the different versions of the programs. Thus, each module sets in the environment vars the path for a specific program. Obviously, this will change depending on the machine/infrastructure that you want to test, and maybe in your case, you need to do this manually (modifying LD_LIBRARY_PATH, PATH, ...)

$ module load gcc openmpi zlib boost python git  gsl imkl openblas hdf5/1.10.3

To install SACESS+peTAB the first time:
    
$ make PARPE=Boehm (the first time it requires time)
	
If you check "bin" folder:
	
$ bin/paralleltestbed_Boehm (it is the specific executable to run Boehm problem)
	
If you want run another benchmarks (i.e. Borghans) you only need to do:
	
$ make PARPE=Borghans
	
And you obtain another executable in bin folder:
	
$ bin/paralleltestbed_Borghans
	
We have integrated the following benchmarks (some of them do not work well):

$ make PARPE=Alkan
$ make PARPE=Bachmann
$ make PARPE=Beer
$ make PARPE=Bertozzi
$ make PARPE=Blasi
$ make PARPE=Boehm
$ make PARPE=Borghans
$ make PARPE=Brannmark
$ make PARPE=Bruno
$ make PARPE=Chen
$ make PARPE=Crauste
$ make PARPE=Elowitz
$ make PARPE=Fiedler
$ make PARPE=Fujita
$ make PARPE=Giordano
$ make PARPE=Isensee
$ make PARPE=Laske
$ make PARPE=Lucarelli
$ make PARPE=Okuonghae
$ make PARPE=Oliveira
$ make PARPE=Perelson
$ make PARPE=Rahman
$ make PARPE=Raimundez
$ make PARPE=SalazarCavazos
$ make PARPE=Schwen
$ make PARPE=Sneyd
$ make PARPE=Weber
$ make PARPE=Zhao
$ make PARPE=Zheng


## Configuration

Each peTAB benchmark has a configure folder: 
	
$ input/Boehm_JProteomeRes2014_SACESS.xml
	
For more specific details about the configuration of SaCeSS, check the manual:
	
$ doc/manual/DOCUMENTATION_SACESS_SOFTWARE.pdf


## Run

$ mpirun -np 10 bin/paralleltestbed_Boehm inputs/Boehm_JProteomeRes2014_SACESS.xml output/test_Boehm_01
	
To run SaCeSS + PEtab without problems, we must have all the environment variables loaded (remember this, especially when working in queue-based systems).  In my case, my script to run SaCeSS is the following:

module load gcc openmpi/4.1.1_ft3 boost gsl hdf5 python jdk

export LD_LIBRARY_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/ThirdParty-HSL/install/lib:$LD_LIBRARY_PATH
export C_INCLUDE_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/opt/libffi/include:$C_INCLUDE_PATH
export LD_LIBRARY_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/install/lib:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/ceres-solver-2.0.0/build/install/lib64:$LD_LIBRARY_PATH
export CMAKE_PREFIX_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/build:$CMAKE_PREFIX_PATH
export CMAKE_PREFIX_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/ceres-solver-2.0.0/build/install:$CMAKE_PREFIX_PATH
export ParPE=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/build
export ParPE_INCLUDE_DIRS=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/include
export CMAKE_PREFIX_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/install:$CMAKE_PREFIX_PATH
export PKG_CONFIG_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3:$PKG_CONFIG_PATH
export PKG_CONFIG_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/ceres-solver-2.0.0/build:$PKG_CONFIG_PATH
export PKG_CONFIG_PATH=/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/bin/pkg-config:$PKG_CONFIG_PATH
export LD_LIBRARY_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/CBLAS/lib:$LD_LIBRARY_PATH
export C_INCLUDE_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/CBLAS/include:$C_INCLUDE_PATH
export HDF5_BASE=/opt/cesga/2020/software/Compiler/gcccore/system/hdf5/1.12.1
export PYTHONPATH=/home/csic/gim/dro/.local/lib/python3.9/site-packages
export PKG_CONFIG_PATH=/opt/cesga/2020/software/Compiler/gcccore/system/hdf5/1.12.1/lib/pkgconfig:$PKG_CONFIG_PATH
export PKG_CONFIG_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/ThirdParty-HSL/install/lib/pkgconfig:$PKG_CONFIG_PATH
export C_INCLUDE_PATH=/home/csic/gim/dro/.local/lib/python3.9/site-packages/amici/include:$C_INCLUDE_PATH
export LD_LIBRARY_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/spdlog/build:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/install/lib:$LD_LIBRARY_PATH
export LD_RUN_PATH=/mnt/netapp1/Store_CSIC/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/install/lib:$LD_RUN_PATH
	
For more specific details about how SaCeSS works, check the manual:

$ doc/manual/DOCUMENTATION_SACESS_SOFTWARE.pdf

