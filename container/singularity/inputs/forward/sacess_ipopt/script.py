import os

# Directory where the files are located
directory = '.'

# Iterate over the files in the directory
for filename in os.listdir(directory):
    # Check if the file ends with '_sacess_adjoint.xml'
    if filename.endswith('_sacess_forward.xml'):
        # Generate the new name
        new_filename = filename.replace('_sacess_forward.xml', '_sacess_IPOPT_forward.xml')
        
        # Full path of the original and new file
        old_file = os.path.join(directory, filename)
        new_file = os.path.join(directory, new_filename)
        
        # Rename the file
        os.rename(old_file, new_file)
        print(f'Renamed: {old_file} -> {new_file}')
        
        # Read the XML file content
        with open(new_file, 'r') as file:
            content = file.read()
        
        # Modify the XML content: Replace <local_search> and <solver> fields
        updated_content = content.replace(
            '<local_search> 0 </local_search>',
            '<local_search> 1 </local_search>'
        ).replace(
            '<solver> dhc </solver>',
            '<solver> parPE </solver>'
        )
        
        # Write the updated content back to the file
        with open(new_file, 'w') as file:
            file.write(updated_content)
        print(f'Modified: {new_file}')

print("Renaming and modifications completed.")
