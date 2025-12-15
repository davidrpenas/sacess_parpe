path="parpe_$1"
fileh5="$1.h5"
echo "$path"
cp modify_tol_hdf5.py $path
cp modify_hdf5.py $path
cp CMakeLists.txt $path
cd $path
pwd
echo "python3 modify_hdf5.py $fileh5"
python3 modify_hdf5.py $fileh5
echo "python3 modify_tol_hdf5.py $fileh5"
python3 modify_tol_hdf5.py $fileh5
cd ..
