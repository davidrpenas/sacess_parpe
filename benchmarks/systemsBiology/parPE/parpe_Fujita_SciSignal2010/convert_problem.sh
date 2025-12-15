#!/bin/bash

# Check if an input file is provided as an argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 <input_file.h5>"
    exit 1
fi

# Input file
INPUT_FILE=$1

# Check if the input file exists
if [ ! -f "$INPUT_FILE" ]; then
    echo "Error: The file '$INPUT_FILE' does not exist."
    exit 1
fi

# Generate output file names
FORWARD_FILE="${INPUT_FILE%.h5}_forward.h5"
ADJOINT_FILE="${INPUT_FILE%.h5}_adjoint.h5"

# Run the Python scripts with the corresponding files
echo "Modifying sensitivity in ${INPUT_FILE}..."
python modify_sens.py "$INPUT_FILE"
if [ $? -ne 0 ]; then
    echo "Error running modify_sens.py"
    exit 1
fi

echo "Generating ${FORWARD_FILE}..."
python modify_hdf5.py "$FORWARD_FILE"
if [ $? -ne 0 ]; then
    echo "Error running modify_hdf5.py for ${FORWARD_FILE}"
    exit 1
fi

echo "Generating ${ADJOINT_FILE}..."
python modify_hdf5.py "$ADJOINT_FILE"
if [ $? -ne 0 ]; then
    echo "Error running modify_hdf5.py for ${ADJOINT_FILE}"
    exit 1
fi

echo "Modifying tolerances in ${ADJOINT_FILE}..."
python modify_tol_hdf5.py "$ADJOINT_FILE"
if [ $? -ne 0 ]; then
    echo "Error running modify_tol_hdf5.py for ${ADJOINT_FILE}"
    exit 1
fi

echo "Modifying tolerances in ${FORWARD_FILE}..."
python modify_tol_hdf5.py "$FORWARD_FILE"
if [ $? -ne 0 ]; then
    echo "Error running modify_tol_hdf5.py for ${FORWARD_FILE}"
    exit 1
fi

echo "Processing completed successfully."
