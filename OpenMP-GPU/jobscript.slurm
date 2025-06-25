#!/bin/bash

# Slurm job options (name, compute nodes, job time)
#SBATCH --job-name=pi
#SBATCH --partition=gpu
#SBATCH --qos=reservation
#SBATCH --reservation=tc069_1525359
#SBATCH --gres=gpu:1
#SBATCH --time=00:01:00

# Replace [budget code] below with your budget code (e.g. t01)
##SBATCH --account=[budget code]

module load gcc
module load nvidia/nvhpc

srun -n 1 ./pi
