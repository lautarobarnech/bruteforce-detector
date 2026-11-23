#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {

    if (argc < 2 ) {
        std::cout << "Falta el archivo a analizar." << "\n";
        std::cout << "Uso: ./bruteforce-detector <archivo>" << "\n";
        return 1;
    }

    std::ifstream archivo(argv[1]);
    if (!archivo) {
        std::cout << "No se pudo abrir " << argv[1] << "\n";
        return 1;
    }

    std::string linea;
    int contador = 0;
    while (std::getline(archivo, linea)) {
        if ((linea.find("]: Failed password for ") != std::string::npos) || 
            (linea.find("]: Failed keyboard-interactive/pam for ") != std::string::npos)) {  // solo intentos fallidos.
            contador++;
        }
    }
    
    std::cout << "Intentos Fallidos: " << contador << "\n";
    return 0;

}