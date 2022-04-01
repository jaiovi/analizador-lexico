//////////// Resaltador de Sintaxis ////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // pair
#include <windows.h>
#include "Token.h"

//////////// Variables Globales ////////////

std::vector<std::string> PALABRAS_RESERVADAS { "if", "else", "do", "while", "break", "return" };
std::vector<std::string> TIPO_DATOS { "int", "string", "bool", "float", "double", "vector" };
std::vector<std::string> OPERADORES { "+", "-", "++", "--", "*", "**", "/", "%" };
std::vector<std::string> COMPARADORES_BOOLEANOS { "==", "&&", "||", "!=" };

std::string COMENTARIOS = "//";
std::string ASIGNACION = "=";
std::string LIMITE = ";";
std::string DOS_PUNTOS = ":";
std::string DOLLAR = "$";
std::string GUION_BAJO = "_";
std::string ABRE_PAR = "(";
std::string CIERRA_PAR = ")";

std::pair<int,int> RANGO_LETRAS_MIN (97,123);
std::pair<int,int> RANGO_LETRAS_MAY (66,91);
std::pair<int,int> RANGO_DIG (48,57);

//////////// Metodos Auxiliares ////////////

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

boolean es_operador (std::string cadena) {
    for (std::string palabra : OPERADORES) {
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

    std::vector<Token> lista_tokens = analisis_lexico(nombre_archivo);

    for (Token tk : lista_tokens) {
        tk.print();
    }

    return 0;
}
