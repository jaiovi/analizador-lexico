#include "Scanner.h"

Scanner::Scanner () {
	this->codigo_fuente = "";
}

Scanner::Scanner (std::string codigo_fuente) {
	this->codigo_fuente = codigo_fuente;
}

void Scanner::enlista_tokens () {
	std::vector <std::string> cadenas = lista_palabras();
	// Asignando tokens a los lexemas
	for (std::string lexema : cadenas) {
		if (lexema == INTEGER) {
			this->lista_tokens.push_back(Token("tk_int", lexema, this->lista_tokens.size()));
		} else if (lexema == FLOAT_POINT) {
			this->lista_tokens.push_back(Token("tk_float", lexema, this->lista_tokens.size()));
		} else if (lexema == PROGRAM) {
			this->lista_tokens.push_back(Token("tk_program", lexema, this->lista_tokens.size()));
		} else if (lexema == VARIABLES) {
			this->lista_tokens.push_back(Token("tk_variable", lexema, this->lista_tokens.size()));
		} else if (lexema == BEGIN) {
			this->lista_tokens.push_back(Token("tk_begin", lexema, this->lista_tokens.size()));
		} else if (lexema == END) {
			this->lista_tokens.push_back(Token("tk_end", lexema, this->lista_tokens.size()));
		} else if (lexema == READ) {
			this->lista_tokens.push_back(Token("tk_read", lexema, this->lista_tokens.size()));
		} else if (lexema == WRITE) {
			this->lista_tokens.push_back(Token("tk_write", lexema, this->lista_tokens.size()));
		} else {

		}
	}
}

std::vector< std::string > Scanner::lista_palabras() { // O(n)
	std::vector<std::string> lista_palabras;
    std::string cadena = "";
	bool comentario = false;

    for (char letra : this->codigo_fuente) {
		if (comentario) {
			continue;
		} else if (cadena == "//") {
            // Ignorando comentario
            cadena = "";
            comentario = true;
        }
        else if (letra != 32 && letra != 9) {
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