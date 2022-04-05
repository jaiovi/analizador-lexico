//////////// Resaltador de Sintaxis ////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // pair
#include <windows.h>
#include "Token.h"
#include "Scanner.h"

//////////// Main de programa ////////////

int main(int argc, char const *argv[])
{
    std::string nombre_archivo = "programa.txt";

    std::string programa_fuente;

    // Leyendo desde archivo
    std::ifstream Lector(nombre_archivo);
    std::string linea;

    // Revisando las lineas del programa
    while (std::getline(Lector, linea))
    {
        programa_fuente += linea;
        programa_fuente += char(9);
    }

    Scanner scanner = Scanner(programa_fuente);
    std::vector<Token> tokens = scanner.escanear();

    for (Token tk : tokens) {
        tk.print();
    }

    return 0;
}
