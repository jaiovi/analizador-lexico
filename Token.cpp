#include "Token.h"

// Constructor por default de la clase Token
// Complejidad: O(1)
Token::Token() {
	this->tipo_token = "";
	this->data = "";
	this->index = -1;
}

// Constructor de la clase Token
// Complejidad: O(1)
Token::Token(std::string tipo_token, std::string data, int index) {
	this->tipo_token = tipo_token;
	this->data = data;
	this->index = index;
}

// Imprime contenidos del Token
// Complejidad: O(1)
void Token::print() {
	std::cout << "(" << this->tipo_token << ",\t";
	std::cout << this->data << ",\t";
	std::cout << this->index << ")";
	std::cout << std::endl;
}

// Regresa el tipo de token
//Complejidad: O(1)
std::string Token::tipo() {
	return this->tipo_token;
}

// Regresa el atributo valor ligado al Token
// Complejidad: O(1)
std::string Token::cadena() {
	return this->data;
}

// Regresa la posicion del token
// Complejidad: O(1)
int Token::indice() {
	return this->index;
}