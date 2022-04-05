//////////// Resaltador de Sintaxis ////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // pair
#include <windows.h>
#include "Token.h"
#include "Scanner.h"

//////////// Variables Globales ////////////

std::vector<std::string> PALABRAS_RESERVADAS { "if", "else", "do", "while", "break", "return" };
std::vector<std::string> TIPO_DATOS { "int", "string", "bool", "float", "double", "vector" };
std::vector<std::string> OPERADORES_BINARIOS { "+", "-", "*", "**", "/", "%" };
std::vector<std::string> OPERADORES_UNITARIOS { "++", "--" };
std::vector<std::string> COMPARADORES_BOOLEANOS { "==", "&&", "||", "!=" };

std::string COMENTARIOS = "//";
std::string ASIGNACION = "=";
std::string LIMITE = ";";
std::string DOS_PUNTOS = ":";
std::string DOLLAR = "$";
std::string GUION_BAJO = "_";
std::string ABRE_PAR = "(";
std::string CIERRA_PAR = ")";
std::string ABRE_LLAVE = "{";
std::string CIERRA_LLAVE = "}";
std::string punto = ".";

std::pair<int,int> RANGO_LETRAS_MIN (97,123);
std::pair<int,int> RANGO_LETRAS_MAY (66,91);
std::pair<int,int> RANGO_DIG (48,57);

//////////// Metodos GUI ////////////

void print_256_colours_txt()
{
    for (int i = 0; i < 256; i++)
    {
        if (i % 16 == 0 && i != 0)
            std::cout << std::endl;
        printf("\033[38;5;%dm %3d\033[m", i, i);
    }
}

void print_color(std::string word, int color) {
	
}

Token siguiente_token(std::string cadena) {
    std::string token = "";
    Token res;

    return res;
}

//////////// Metodos Auxiliares ////////////

// Regresa una lista de cadenas en una linea del codigo fuente
std::vector<std::string> cadenas_en_linea (std::string linea) {
    std::vector<std::string> lista_palabras;
    std::string cadena = "";

    for (char letra : linea) {
        if (cadena == "//") {
            // Ignorando comentario
            cadena = "";
            break;
        }
        else if (letra != ' ' && letra != 9) {
            cadena += letra;
        }
        else {
            if (cadena != "") {
                lista_palabras.push_back(cadena);
                cadena = "";
            }
        }
    }
    if (cadena != "") {
        lista_palabras.push_back(cadena);
        cadena = "";
    }

    return lista_palabras;
}

boolean es_reservado (std::string cadena) {
    for (std::string palabra : PALABRAS_RESERVADAS) {
        if (cadena == palabra) return true;
    }
    return false;
}

boolean es_tipo_dato (std::string cadena) {
    for (std::string palabra : TIPO_DATOS) {
        if (cadena == palabra) return true;
    }
    return false;
}

boolean es_operador_binario (std::string cadena) {
    for (std::string palabra : OPERADORES_BINARIOS) {
        if (cadena == palabra) return true;
    }
    return false;
}

boolean es_operador_unitario (std::string cadena) {
    for (std::string palabra : OPERADORES_UNITARIOS) {
        if (cadena == palabra) return true;
    }
    return false;
}

boolean es_comparador (std::string cadena) {
    for (std::string palabra : COMPARADORES_BOOLEANOS) {
        if (cadena == palabra) return true;
    }
    return false;
}

void asignacion_token (std::vector<Token>& lista_tokens, std::string cadena) {

    // Palabras reservadas
    if (es_reservado(cadena)) {
        lista_tokens.push_back(Token("tk_palabra_reservada", cadena, lista_tokens.size()));
        return;
    // Operadores binarios
    } else if (es_operador_binario(cadena)) {
        lista_tokens.push_back(Token("tk_operador_binario", cadena, lista_tokens.size()));
        return;
    // Operadores tipo de datos
    } else if (es_tipo_dato(cadena)) {
        lista_tokens.push_back(Token("tk_tipo_dato", cadena, lista_tokens.size()));
        return;
    }

    std::string subcadena = "";
    std::string dig = "";

    for (char c : cadena) {
        dig += c;
        if (dig == ASIGNACION) {
            // Verificando si la subcadena es una palabra reservada
            if (subcadena.length() > 0) (es_reservado(subcadena)) ? 
            lista_tokens.push_back(Token("tk_palabra_reservada", subcadena, lista_tokens.size())) : 
            lista_tokens.push_back(Token("tk_id", subcadena, lista_tokens.size()));
            subcadena = "";

            // Agregando nuevo token
            lista_tokens.push_back(Token("tk_asig", dig, lista_tokens.size()));
        }
        else if (dig == LIMITE) {
            // Verificando si la subcadena es una palabra reservada
            if (subcadena.length() > 0) (es_reservado(subcadena)) ? 
            lista_tokens.push_back(Token("tk_palabra_reservada", subcadena, lista_tokens.size())) : 
            lista_tokens.push_back(Token("tk_id", subcadena, lista_tokens.size()));
            subcadena = "";

            // Agregando nuevo token
            lista_tokens.push_back(Token("tk_lim", dig, lista_tokens.size()));
        }
        else if (dig == DOS_PUNTOS) {
            // Verificando si la subcadena es una palabra reservada
            if (subcadena.length() > 0) (es_reservado(subcadena)) ? 
            lista_tokens.push_back(Token("tk_palabra_reservada", subcadena, lista_tokens.size())) : 
            lista_tokens.push_back(Token("tk_id", subcadena, lista_tokens.size()));
            subcadena = "";

            // Agregando nuevo token
            lista_tokens.push_back(Token("tk_dos_puntos", dig, lista_tokens.size()));
        }
        else if (dig == DOLLAR) {
            // Verificando si la subcadena es una palabra reservada
            if (subcadena.length() > 0) (es_reservado(subcadena)) ? 
            lista_tokens.push_back(Token("tk_palabra_reservada", subcadena, lista_tokens.size())) : 
            lista_tokens.push_back(Token("tk_id", subcadena, lista_tokens.size()));
            subcadena = "";

            // Agregando nuevo token
            lista_tokens.push_back(Token("tk_dollar", dig, lista_tokens.size()));
        }
        // else if (dig == GUION_BAJO) {
        //     // Verificando si la subcadena es una palabra reservada
        //     if (subcadena.length() > 0) (es_reservado(subcadena)) ? 
        //     lista_tokens.push_back(Token("tk_palabra_reservada", subcadena, lista_tokens.size())) : 
        //     lista_tokens.push_back(Token("tk_id", subcadena, lista_tokens.size()));
        //     subcadena = "";

        //     // Agregando nuevo token
        //     lista_tokens.push_back(Token("tk_guin_bajo", dig, lista_tokens.size()));
        // }
        else if (dig == ABRE_PAR) {
            // Verificando si la subcadena es una palabra reservada
            if (subcadena.length() > 0) (es_reservado(subcadena)) ? 
            lista_tokens.push_back(Token("tk_palabra_reservada", subcadena, lista_tokens.size())) : 
            lista_tokens.push_back(Token("tk_id", subcadena, lista_tokens.size()));
            subcadena = "";

            // Agregando nuevo token
            lista_tokens.push_back(Token("tk_abre_par", dig, lista_tokens.size()));
        }
        else if (dig == CIERRA_PAR) {
            // Verificando si la subcadena es una palabra reservada
            if (subcadena.length() > 0) (es_reservado(subcadena)) ? 
            lista_tokens.push_back(Token("tk_palabra_reservada", subcadena, lista_tokens.size())) : 
            lista_tokens.push_back(Token("tk_id", subcadena, lista_tokens.size()));
            subcadena = "";

            // Agregando nuevo token
            lista_tokens.push_back(Token("tk_cierra_par", dig, lista_tokens.size()));
        }
        else {
            subcadena += c;
        }        
        dig = "";
    }
    
    if (subcadena.length() > 0) (es_reservado(subcadena)) ? 
    lista_tokens.push_back(Token("tk_palabra_reservada", subcadena, lista_tokens.size())) : 
    lista_tokens.push_back(Token("tk_id", subcadena, lista_tokens.size()));

    // Token prueba = Token("tk_prueba", cadena, 1);
    // lista_tokens.push_back(prueba);
}

std::vector<Token> analisis_lexico(std::string nombre_archivo) {
    // Lista de tokens por regresar
    std::vector<Token> lista_tokens;
    std::vector<std::string> cadenas;

    // Leyendo desde archivo
    std::ifstream Lector(nombre_archivo);
    std::string linea;

    // Revisando las lineas del programa
    while (std::getline(Lector, linea))
    {
        cadenas = cadenas_en_linea(linea);
        // Por cada cadena en la linea se obtienen los tokens, segmentando cadena si es necesario
        for (std::string cadena : cadenas) {
            asignacion_token(lista_tokens, cadena);
        }
    }
    return lista_tokens;
}

//////////// Main de programa ////////////

int main(int argc, char const *argv[])
{
    std::string nombre_archivo = "programa.txt";

    std::string programa_fuente;

    std::vector<Token> lista_tokens = analisis_lexico(nombre_archivo);

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
    std::vector<std::string> lista = scanner.lista_palabras();
    for (std::string palabra : lista) {
        std::cout << palabra << std::endl;
    }

    // std::cout << programa_fuente << std::endl;

    // for (Token tk : lista_tokens) {
    //     tk.print();
    // }

    return 0;
}
