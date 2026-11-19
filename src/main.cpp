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

    while (std::getline(archivo, linea)) {
        std::cout << linea << "\n";
    }

    return 0;

}