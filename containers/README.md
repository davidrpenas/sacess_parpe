# Containers on the FT3 Supercomputers

## Specifications

https://www.cesga.es/en/infrastructures/computing/

## Download image

https://drive.google.com/file/d/1X-w_WrfAHNYtsaquR0LkyUFfh6JU6DfY/view?usp=sharing

## Example Job: job_example.sh

$1 -> /home/sacess_parpe/containers -> container path

$2 -> Boehm -> benchmark name

$3 -> /home/sacess_parpe/inputs/adjoint/sacess_ipopt/Boehm_JProteomeRes2014_sacess_ipopt_adjoint.xml -> input file 

$4 -> /home/sacess_parpe/results -> output path

$5 -> Boehm_adjoint_sacess_ipopt_01 -> specific result folder name


$ cat job_example.sh 

#!/bin/bash

#SBATCH -t 04:00:00 

#SBATCH -n 12 

#SBATCH -N 1 

#SBATCH --mem-per-cpu=1G 

module load singularity

cpus=$SLURM_NTASKS

unset $(compgen -v | grep "^SLURM")

singularity exec -B $4:/opt/sacess_petab/output $1/sacess_parpe.sif mpirun -np $cpus --oversubscribe /opt/sacess_petab/bin/paralleltestbed_$2 /opt/sacess_petab/$3 /opt/sacess_petab/output/$5



## Submit to the Queue Manager:


## 10 runs with adjoints and without local solvers

sbatch job_example.sh Boehm /home/sacess_parpe/containers /home/sacess_parpe/inputs/adjoint/sacess_ipopt/Boehm_JProteomeRes2014_sacess_ipopt_adjoint.xml /home/sacess_parpe/results/Boehm_adjoint_sacess_ipopt_01

sbatch job_example.sh Boehm /home/sacess_parpe/containers /home/sacess_parpe/inputs/adjoint/sacess_ipopt/Boehm_JProteomeRes2014_sacess_ipopt_adjoint.xml /home/sacess_parpe/results/Boehm_adjoint_sacess_ipopt_02

...

sbatch job_example.sh Boehm /home/sacess_parpe/containers /home/sacess_parpe/inputs/adjoint/sacess_ipopt/Boehm_JProteomeRes2014_sacess_ipopt_adjoint.xml /home/sacess_parpe/results/Boehm_adjoint_sacess_ipopt_10

## setup

The setup_ft3_scripts folder provides a framework for performing benchmark calculations, including input files and scripts for execution in a SLURM environment. 

The only requirement is to place the SIF file in the containers folder.







