# Containers on HPC Infrastructures

This repository provides containerized workflows for running **SaCeSS+parPE**
benchmarks on HPC systems using **Singularity/Apptainer** and **SLURM**.

## System Specifications

As an example, we refer to the **FINISTERRAE III (FT3)** supercomputer operated by
**CESGA (Galicia Supercomputing Center)**.

Detailed hardware and system specifications are available at:  
https://www.cesga.es/en/infrastructures/computing/

## Download the Container Image

The Singularity image (`.sif`) can be downloaded from:

https://drive.google.com/file/d/1X-w_WrfAHNYtsaquR0LkyUFfh6JU6DfY/view?usp=sharing

Place the downloaded file in the `containers/` directory.

## Build the Image from the Dockerfile

TBD

## Example SLURM Job Using Singularity

### `job_example.sh`

This script executes a single SaCeSS + parPE benchmark run inside a Singularity
container using MPI.

#### Arguments

- `$1` – Container directory  
  *(e.g. `/home/sacess_parpe/containers`)*

- `$2` – Benchmark name  
  *(e.g. `Boehm`)*

- `$3` – Input XML file  
  *(e.g. `/home/sacess_parpe/inputs/adjoint/sacess_ipopt/Boehm_JProteomeRes2014_sacess_ipopt_adjoint.xml`)*

- `$4` – Output base directory  
  *(e.g. `/home/sacess_parpe/results`)*

- `$5` – Run-specific output directory name  
  *(e.g. `Boehm_adjoint_sacess_ipopt_01`)*

#### Script

```bash
#!/bin/bash
#SBATCH -t 04:00:00
#SBATCH -n 12
#SBATCH -N 1
#SBATCH --mem-per-cpu=1G

module load singularity

CONTAINERS_DIR="$1"
BENCH="$2"
INPUT_XML="$3"
OUTPUT_BASE="$4"
RUN_NAME="$5"

cpus="${SLURM_NTASKS:-1}"

# Avoid leaking SLURM variables inside the container
unset $(compgen -v | grep "^SLURM")

# Ensure output directory exists on the host
mkdir -p "$OUTPUT_BASE/$RUN_NAME"

singularity exec \
  -B "${OUTPUT_BASE}:/opt/sacess_petab/output" \
  "${CONTAINERS_DIR}/sacess_parpe.sif" \
  mpirun -np "${cpus}" --oversubscribe \
  "/opt/sacess_petab/bin/paralleltestbed_${BENCH}" \
  "${INPUT_XML}" \
  "/opt/sacess_petab/output/${RUN_NAME}"
```

## Submitting Jobs to SLURM

```bash
CONTAINERS=/home/sacess_parpe/containers
BENCH=Boehm
INPUT=/home/sacess_parpe/inputs/adjoint/sacess_ipopt/Boehm_JProteomeRes2014_sacess_ipopt_adjoint.xml
OUT=/home/sacess_parpe/results

sbatch job_example.sh "$CONTAINERS" "$BENCH" "$INPUT" "$OUT" Boehm_adjoint_sacess_ipopt_01
sbatch job_example.sh "$CONTAINERS" "$BENCH" "$INPUT" "$OUT" Boehm_adjoint_sacess_ipopt_02
sbatch job_example.sh "$CONTAINERS" "$BENCH" "$INPUT" "$OUT" Boehm_adjoint_sacess_ipopt_03
sbatch job_example.sh "$CONTAINERS" "$BENCH" "$INPUT" "$OUT" Boehm_adjoint_sacess_ipopt_04
sbatch job_example.sh "$CONTAINERS" "$BENCH" "$INPUT" "$OUT" Boehm_adjoint_sacess_ipopt_05
sbatch job_example.sh "$CONTAINERS" "$BENCH" "$INPUT" "$OUT" Boehm_adjoint_sacess_ipopt_06
sbatch job_example.sh "$CONTAINERS" "$BENCH" "$INPUT" "$OUT" Boehm_adjoint_sacess_ipopt_07
sbatch job_example.sh "$CONTAINERS" "$BENCH" "$INPUT" "$OUT" Boehm_adjoint_sacess_ipopt_08
sbatch job_example.sh "$CONTAINERS" "$BENCH" "$INPUT" "$OUT" Boehm_adjoint_sacess_ipopt_09
sbatch job_example.sh "$CONTAINERS" "$BENCH" "$INPUT" "$OUT" Boehm_adjoint_sacess_ipopt_10
```

## Setup

# Required directory structure

```bash
containers/
inputs/
results/
setup_ft3_scripts/
```

# Place the Singularity image here
containers/sacess_parpe.sif








