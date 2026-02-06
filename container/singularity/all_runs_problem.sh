!#/bin/bash

export bench=$1
export script=$2

export sens=adjoint
export solver=sacess_ipopt
for i in {1..10}
do
    printf -v num "%02d" $i
    echo "sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num"
    sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num
done
export solver=sacess_dhc
for i in {1..10}
do
    printf -v num "%02d" $i
    echo "sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num"
    sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num
done
export solver=sacess
for i in {1..10}
do
    printf -v num "%02d" $i
    echo "sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num"
    sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num
done
export sens=forward
export solver=sacess_ipopt
for i in {1..10}
do
    printf -v num "%02d" $i
    echo "sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num"
    sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num
done
export solver=sacess_dhc
for i in {1..10}
do
    printf -v num "%02d" $i
    echo "sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num"
    sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num
done
export solver=sacess
for i in {1..10}
do
    printf -v num "%02d" $i
    echo "sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num"
    sbatch ${script} $bench containers/sacess_parpe.sif inputs/$sens/$solver/${bench}_${solver}_${sens}.xml results/${bench}_${sens}_${solver}_$num
done





