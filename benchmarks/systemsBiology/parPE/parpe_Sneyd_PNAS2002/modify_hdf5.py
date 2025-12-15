import h5py
import sys

try:
    h5 = h5py.File(sys.argv[1], 'r+')     # open the file 
except:
    sys.exit("ERROR. Did you make a mistake in the spelling")

print(h5.name)

numcells1 = h5['optimizationOptions']
numcells1.attrs['numStarts'] = 1
numcells1.attrs['multistartsInParallel'] = 0

print(numcells1)

del h5['optimizationOptions/randomStarts']

#data['DATA'] = 2                      # assign new values to data
h5.close()   
