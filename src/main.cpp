#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    std::ifstream archivo(argv[1]);

    if (!archivo) {
        std::cout << "No se pudo abrir " << argv[1] << "\n";
        return 1;
    }

    std::string linea;

    int contador = 0;
    while (std::getline(archivo, linea)) {
        if (linea.find("Failed password") != std::string::npos) {  // solo intentos fallidos.
            contador++;
        }
    }
    
    std::cout << "Intentos Fallidos: " << contador << "\n";
    return 0;

}