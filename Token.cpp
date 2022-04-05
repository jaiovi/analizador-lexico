#include "Token.h"

Token::Token() {
	this->tipo_token = "";
	this->data = "";
	this->index = -1;
}

Token::Token(std::string tipo_token, std::string data, int index) {
	this->tipo_token = tipo_token;
	this->data = data;
	this->index = index;
}

void Token::print() {
	std::cout << "(" << this->tipo_token << ",\t";
	std::cout << this->data << ",\t";
	std::cout << this->index << ")";
	std::cout << std::endl;
}

std::string Token::tipo() {
	return this->tipo_token;
}

std::string Token::cadena() {
	return this->data;
}

int Token::indice() {
	return this->index;
}