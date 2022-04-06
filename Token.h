#ifndef TOKEN
#define TOKEN

// Class Token
#include <utility> // pair
#include <string> // string
#include <iostream>

// Creamos la clase Token. Tiene como atributo un nombre y un valor. El nombre 
// representa un tipo de unidad lexica o una secuencia de caracteres equivalente
// a un identificador. El analizador sintactico toma los token como entrada.
class Token {
	private:
	std::string tipo_token;
	std::string data;
	int index;

	public:
	Token();
	Token(std::string tipo_token, std::string data, int index);
	void print();

	std::string tipo();
	std::string cadena();
	int indice();
};

#endif