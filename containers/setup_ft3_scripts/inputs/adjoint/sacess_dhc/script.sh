#!/bin/bash

# Directorio donde están los archivos
dir=""

# Iterar sobre todos los archivos .xml en el directorio
for file in "$dir"*.xml
do
	base_name=$(basename "$file" | cut -d'_' -f1)
	    
	new_name="${base_name}_sacess_dhc_adjoint.xml"
		        
	mv "$file" "$dir$new_name"
done
