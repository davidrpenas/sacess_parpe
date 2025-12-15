echo "$1"

h5dump -d "/parameters/lowerBound" parpe_$1/$1.h5
h5dump -d "/parameters/upperBound" parpe_$1/$1.h5

