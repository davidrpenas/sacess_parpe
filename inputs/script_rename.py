import os
import shutil  # Import for copying files

# Directory where the files are located
directory = '.'

# Iterate over the files in the directory
for filename in os.listdir(directory):
    # Check if the file ends with '_adjoint.xml'
    if filename.endswith('_adjoint.xml'):
        # Generate the new name
        new_filename = filename.replace('_adjoint.xml', '_forward.xml')
        
        # Full path of the original and new file
        old_file = os.path.join(directory, filename)
        new_file = os.path.join(directory, new_filename)
        
        # Copy the original file to create a new file
        shutil.copy(old_file, new_file)
        print(f'Copied: {old_file} -> {new_file}')
        
        # Read the XML file content from the new file
        with open(new_file, 'r') as file:
            content = file.read()
        
        # Modify the XML content: Replace <amici_sensi> 2 with <amici_sensi> 1
        updated_content = content.replace(
            '<amici_sensi> 2 </amici_sensi>',
            '<amici_sensi> 1 </amici_sensi>'
        )
        
        # Write the updated content back to the new file
        with open(new_file, 'w') as file:
            file.write(updated_content)
        print(f'Modified: {new_file}')

print("Copying and modifications completed.")
