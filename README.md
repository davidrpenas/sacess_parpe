# SaCeSS+PEtab

## A modified version of SaCeSS to work with problems in PEtab format

This repository provides an initial integration between the **SaCeSS** solver and
optimization problems defined in the **PEtab** format, using parPE tool.  
The following notes describe how to compile and use the software.

## Installation

First, install **parPE 0.7.0**, as it provides the C implementation of the cost
function used by SaCeSS.

You must apply the parPE patch available in the **parpe_patch/** folder of this repository,
as it includes the modifications required to integrate SaCeSS with PEtab benchmarks.

Once parPE is installed, modify the SaCeSS `Makefile` to point to the
corresponding parPE directories. In our case:

```
PATHPARPE=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE
PATHHDF5=/opt/cesga/2020/software/Compiler/gcccore/system/hdf5/1.12.1
PATHBOOST=/opt/cesga/2020/software/Compiler/gcccore/system/boost/1.83.0/lib64
PATHIPOPT=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/install
```


In our case, we also need to call the followings software modules previous to call Makefile. Our supercomputer use a module software system to manage the different versions of the programs. Thus, each module sets in the environment vars the path for a specific program. Obviously, this will change depending on the machine/infrastructure that you want to test, and maybe in your case, you need to do this manually (modifying LD_LIBRARY_PATH, PATH, ...)

```
$ module load gcc/system gcccore/12.3.0 python/3.10.8 openmpi/4.0.5_ft3 boost/1.83.0  cmake/3.23.1 imkl hdf5/1.12.1
```

To install SACESS+peTAB the first time:

```    
$ make PARPE=Boehm (the first time it requires time)
```

If you check "bin" folder:

```
$ bin/paralleltestbed_Boehm (it is the specific executable to run Boehm problem)
```
	
If you want run another benchmarks (i.e. Borghans) you only need to do:

```
$ make PARPE=Borghans
```
	
And you obtain another executable in bin folder:

```	
$ bin/paralleltestbed_Borghans
```
	
We have integrated the following benchmarks (some of them do not work well):

```
$ make PARPE=Armistead
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
$ make PARPE=Raia
$ make PARPE=Raimundez
$ make PARPE=SalazarCavazos
$ make PARPE=Smith
$ make PARPE=Schwen
$ make PARPE=Sneyd
$ make PARPE=Weber
$ make PARPE=Zhao
$ make PARPE=Zheng
```

## Configuration

Each peTAB benchmark has a configure folder: 

```
$ input/Boehm_JProteomeRes2014_SACESS.xml
```

For more specific details about the configuration of SaCeSS, check the manual:
```	
$ doc/manual/DOCUMENTATION_SACESS_SOFTWARE.pdf
```

## Run

```
$ mpirun -np 10 bin/paralleltestbed_Boehm inputs/Boehm_JProteomeRes2014_SACESS.xml output/test_Boehm_01
```
	
To run SaCeSS + PEtab without problems, we must have all the environment variables loaded (remember this, especially when working in queue-based systems).  In my case, my script to run SaCeSS is the following:

```
module load gcc/system gcccore/12.3.0 python/3.10.8 openmpi/4.0.5_ft3 boost/1.83.0  cmake/3.23.1 imkl hdf5/1.12.1

export PARPE_NO_DEBUG=1
export LD_PRELOAD=/opt/cesga/2020/software/Core/imkl/2021.3.0/lib/intel64/libmkl_core.so:/opt/cesga/2020/software/Core/imkl/2021.3.0/lib/intel64/libmkl_sequential.so
export PKG_CONFIG_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/install/lib/pkgconfig:$PKG_CONFIG_PATH
export CMAKE_PREFIX_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/install:$CMAKE_PREFIX_PATH
export LD_LIBRARY_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/install/lib:$LD_LIBRARY_PATH
export PKG_CONFIG_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE/ThirdParty/Ipopt-releases-3.13.3/ThirdParty-HSL/install/lib/pkgconfig:$PKG_CONFIG_PATH
export CMAKE_INCLUDE_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE/include:$CMAKE_INCLUDE_PATH
export PARPE_NUM_SIMULATION_TRIALS=1
export OMP_NUM_THREADS=1
```
	
For more specific details about how SaCeSS works, check the manual:

```
$ doc/manual/DOCUMENTATION_SACESS_SOFTWARE.pdf

