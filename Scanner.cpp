#include "Scanner.h"

Scanner::Scanner () {
	this->codigo_fuente = "";
}

Scanner::Scanner (std::string codigo_fuente) {
	this->codigo_fuente = codigo_fuente;
}

bool Scanner::lexema_reservado(std::string lexema) {
	if (lexema == INTEGER) {
		this->lista_tokens.push_back(Token("tk_int", lexema, this->lista_tokens.size()));
		return true;
	} else if (lexema == FLOAT_POINT) {
		this->lista_tokens.push_back(Token("tk_float", lexema, this->lista_tokens.size()));
		return true;
	} else if (lexema == PROGRAM) {
		this->lista_tokens.push_back(Token("tk_program", lexema, this->lista_tokens.size()));
		return true;
	} else if (lexema == VARIABLES) {
		this->lista_tokens.push_back(Token("tk_variable", lexema, this->lista_tokens.size()));
		return true;
	} else if (lexema == BEGIN) {
		this->lista_tokens.push_back(Token("tk_begin", lexema, this->lista_tokens.size()));
		return true;
	} else if (lexema == END) {
		this->lista_tokens.push_back(Token("tk_end", lexema, this->lista_tokens.size()));
		return true;
	} else if (lexema == READ) {
		this->lista_tokens.push_back(Token("tk_read", lexema, this->lista_tokens.size()));
		return true;
	} else if (lexema == WRITE) {
		this->lista_tokens.push_back(Token("tk_write", lexema, this->lista_tokens.size()));
		return true;
	} else {
		return false;
	}
}

bool Scanner::caracter_reservado (char c) { // O(1)
	std::string lexema = "";
	lexema += c;
	
	if (lexema == SUMA) {
		return true;
	} else if (lexema == RESTA) {
		return true;
	} else if (lexema == MULTIPLICACION) {
		return true;
	} else if (lexema == DIVISION) {
		return true;
	} else if (lexema == DOS_PUNTOS) {
		return true;
	} else if (lexema == PUNTO_COMA) {
		return true;
	} else if (lexema == COMA) {
		return true;
	} else {
		return false;
	}
}

void Scanner::asignar_caracter (char c) { // O(1)
	std::string lexema = "";
	lexema += c;

	if (lexema == SUMA) {
		this->lista_tokens.push_back(Token("tk_suma", lexema, this->lista_tokens.size()));
	} else if (lexema == RESTA) {
		this->lista_tokens.push_back(Token("tk_resta", lexema, this->lista_tokens.size()));
	} else if (lexema == MULTIPLICACION) {
		this->lista_tokens.push_back(Token("tk_mult", lexema, this->lista_tokens.size()));
	} else if (lexema == DIVISION) {
		this->lista_tokens.push_back(Token("tk_div", lexema, this->lista_tokens.size()));
	} else if (lexema == DOS_PUNTOS) {
		this->lista_tokens.push_back(Token("tk_dos_puntos", lexema, this->lista_tokens.size()));
	} else if (lexema == PUNTO_COMA) {
		this->lista_tokens.push_back(Token("tk_punto_coma", lexema, this->lista_tokens.size()));
	} else if (lexema == COMA) {
		this->lista_tokens.push_back(Token("tk_coma", lexema, this->lista_tokens.size()));
	}

	return;
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

void Scanner::enlista_tokens () {
	std::vector <std::string> cadenas = lista_palabras();
	std::string palabra = "";
	// Asignando tokens a los lexemas
	for (std::string lexema : cadenas) {
		if (!lexema_reservado(lexema)) { // Verificando si un lexema es alguna palabra reservado
			// Separando el lexema en caso de varibles pegadas a limitadores u operadores
		    // Ejemplos: 9+3 -- a,b,c,d -- 9*8-2/3
			for (char c : lexema) {
				if (caracter_reservado(c)) { // Verificando si un caracter es reservado
					if (palabra.length() > 0) {
						if (!lexema_reservado(palabra)) // Si no es una palabra reservada, es una variable o dato
						this->lista_tokens.push_back(Token("tk_var", palabra, this->lista_tokens.size()));
						palabra = "";
					}
					asignar_caracter(c);
				} else {
					palabra += c;
				}
			}
			if (palabra.length() > 0) {
				if (!lexema_reservado(palabra)) // Si no es una palabra reservada, es una variable o dato
				this->lista_tokens.push_back(Token("tk_var", palabra, this->lista_tokens.size()));
				palabra = "";
			}
		}
	}
	return;
}

std::vector<Token> Scanner::escanear() {
	enlista_tokens();
	return this->lista_tokens;
}