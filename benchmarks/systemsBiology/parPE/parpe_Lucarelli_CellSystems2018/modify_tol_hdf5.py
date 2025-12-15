import h5py
import sys

try:
    h5 = h5py.File(sys.argv[1], 'r+')     # open the file 
except:
    sys.exit("ERROR. Did you make a mistake in the spelling")

print(h5.name)

numcells1 = h5['amiciOptions']
numcells1.attrs['atol'] = 1.00E-16
numcells1.attrs['rtol'] = 1.00E-8

print("atol "+ str(numcells1.attrs['atol']))
print("rtol "+ str(numcells1.attrs['rtol']))

h5.close()   
