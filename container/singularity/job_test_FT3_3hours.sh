#!/bin/bash
#SBATCH -t 04:00:00
#SBATCH -n 12
#SBATCH -N 1
#SBATCH --mem-per-cpu=1G

module load singularity

cpus=$SLURM_NTASKS
unset $(compgen -v | grep "^SLURM")

singularity exec -B $4:/opt/sacess_petab/output $1/sacess_parpe.sif mpirun -np $cpus --oversubscribe /opt/sacess_petab/bin/paralleltestbed_$2 /opt/sacess_petab/$3 /opt/sacess_petab/output/$5
