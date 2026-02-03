# SaCeSS_parPE

## A modified version of SaCeSS to work with problems in PEtab format using parPE

This repository provides an integration between the **SaCeSS** solver and optimization problems defined in the **PEtab format**, using the **parPE** tool:
```
https://github.com/ICB-DCM/parPE
```
The following notes describe how to compile and use the software.

## Installation

First, install **parPE 0.7.0**, as it provides the C implementation of the cost function used by SaCeSS.

After this, apply the patch included in the **patch/** folder. Simply extract **parpe_sacess_overlay.tar.gz** into your parPE installation folder.

This **patch/** includes the modifications required to integrate SaCeSS with PEtab benchmarks; therefore, its application is essential.

Once modified parPE is installed, modify the **SaCeSS_parPE** Makefile to point to the corresponding parPE directories. In our case:

```
PATHPARPE=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0
PATHHDF5=/opt/cesga/2020/software/Compiler/gcccore/system/hdf5/1.12.1
PATHBOOST=/opt/cesga/2020/software/Compiler/gcccore/system/boost/1.83.0/lib64
PATHIPOPT=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/ThirdParty/Ipopt-releases-3.13.3/install
```

You must set all the environmental variables required to install **parPE**. In our case, since we are working on a supercomputer that utilizes environment modules, it is necessary to load the required software modules before calling the **Makefile**.

Our infrastructure uses a module management system to handle different software versions; therefore, each module automatically configures the environment variables (such as PATH and LD_LIBRARY_PATH) for the specific program.

**[IMPORTANT]** This setup will vary depending on the specific machine or infrastructure you are using. If your system does not support modules, you may need to configure these paths manually (e.g., by modifying your .bashrc or exporting variables directly).

```bash
$ module load gcc/system gcccore/12.3.0 python/3.10.8 openmpi/4.0.5_ft3 boost/1.83.0  cmake/3.23.1 imkl hdf5/1.12.1
```

After this, to install SaCeSS+parPE the first time:

```bash   
$ make PARPE=Boehm (the first time it requires time)
```

If the compilation was successful, verify the **bin/** folder:

```bash
ls -l ./bin
$ bin/paralleltestbed_Boehm (it is the specific executable to run Boehm problem)
```
	
If you want to run other benchmarks (e.g., **Borghans**), simply execute:
```bash
$ make PARPE=Borghans
```
This will generate another executable in the bin/ folder:
```bash
$ bin/paralleltestbed_Borghans
```
	
We have integrated the following benchmarks:

```bash
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

```bash
$ inputs/forward/sacess_dhc/Boehm_sacess_dhc_forward.xml 
```
For instance, the file `Boehm_sacess_dhc_forward.xml` specifies the settings to run the **Boehm** model with **SaCeSS** using **DHC** and **forward sensitivities**.

For more specific details regarding **SaCeSS** configuration, please consult the manual:

```bash
$ doc/manual/DOCUMENTATION_SACESS_SOFTWARE.pdf
```

## Run

```bash
$ mpirun -np 10 bin/paralleltestbed_Boehm inputs/Boehm_JProteomeRes2014_SACESS.xml output/test_Boehm_01
```
To run SaCeSS_parPE correctly, all environment variables must be properly loaded (ensure this is handled, particularly when working with queue-based systems). Below is an example of the script used to run SaCeSS:
```bash
module load gcc/system gcccore/12.3.0 python/3.10.8 openmpi/4.0.5_ft3 boost/1.83.0  cmake/3.23.1 imkl
export PARPE_NO_DEBUG=1
export PARPE_NUM_SIMULATION_TRIALS=1
export OMP_NUM_THREADS=1
LD_LIBRARY_PATH=/mnt/lustre/scratch/nlsas/home/csic/gim/dro/parPE-0.7.0/ThirdParty/Ipopt-releases-3.13.3/install/lib:$LD_LIBRARY_PATH
```
	
For more specific details about how SaCeSS works, check the manual:

```bash
$ doc/manual/DOCUMENTATION_SACESS_SOFTWARE.pdf
```

To use a *singularity-based container*, navigate to the container/ folder and follow the instructions provided there.

