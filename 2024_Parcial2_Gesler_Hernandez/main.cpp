#include <iostream>
#include <fstream>
#include <filesystem>
#include <windows.h>

void crearArchivos(int cantidad) {
    std::string carpeta = (cantidad % 2 == 0) ? "par" : "impar";
    std::string rutaEscritorio = getenv("USERPROFILE") + std::string("\\Desktop\\") + carpeta;

    // Crear la carpeta si no existe
    std::filesystem::create_directory(rutaEscritorio);

    for (int i = 1; i <= cantidad; ++i) {
        std::string nombreArchivo = rutaEscritorio + "\\file" + std::to_string(i) + ".txt";
        std::ofstream archivo(nombreArchivo);

        // Agregar texto al archivo
        for (int linea = 1; linea <= i; ++linea) {
            archivo << "Esta es la línea " << linea << " del archivo file" << i << '\n';
        }

        archivo.close();
    }
}

int main() {
    int cantidad;
    std::cout << "Escriba la cantidad de archivos que desea crear: ";
    std::cin >> cantidad;

    crearArchivos(cantidad);

    return 0;
}
