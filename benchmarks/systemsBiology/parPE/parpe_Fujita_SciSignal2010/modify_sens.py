import h5py
import sys
import shutil

def modify_hdf5(input_file, output_file, sensi_meth, sensi_meth_preeq):
    # Crear una copia del archivo original para no modificarlo directamente
    shutil.copy(input_file, output_file)

    # Abrir el archivo copiado en modo lectura/escritura
    with h5py.File(output_file, "r+") as hdf:
        # Verificar si el grupo /amiciOptions existe
        if "/amiciOptions" in hdf:
            group = hdf["/amiciOptions"]

            # Modificar los atributos
            group.attrs["sensi_meth"] = sensi_meth
            group.attrs["sensi_meth_preeq"] = sensi_meth_preeq

            print(f"Atributos modificados en {output_file}:")
            print(f"  sensi_meth = {sensi_meth}")
            print(f"  sensi_meth_preeq = {sensi_meth_preeq}")
        else:
            print(f"El grupo /amiciOptions no se encontró en {output_file}.")
            return

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Uso: python modify_hdf5.py <archivo_entrada.h5>")
        sys.exit(1)

    # Archivo HDF5 de entrada
    input_file = sys.argv[1]

    # Archivos de salida
    forward_file = input_file.replace(".h5", "_forward.h5")
    adjoint_file = input_file.replace(".h5", "_adjoint.h5")

    # Generar boehn_forward.h5 con sensi_meth = 1 y sensi_meth_preeq = 1
    modify_hdf5(input_file, forward_file, sensi_meth=1, sensi_meth_preeq=1)

    # Generar boehn_adjoint.h5 con sensi_meth = 2 y sensi_meth_preeq = 2
    modify_hdf5(input_file, adjoint_file, sensi_meth=2, sensi_meth_preeq=2)

    print(f"Archivos generados: {forward_file}, {adjoint_file}")