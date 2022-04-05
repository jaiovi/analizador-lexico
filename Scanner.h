// Class Scanners - Analizador Lexico
#include "Token.h"
#include <vector>
#include <string>

class Scanner {
	private:
	std::string codigo_fuente;
	std::vector<Token> lista_tokens;
	// PALABRAS RESERVADAS
	std::string INTEGER = "int";
	std::string FLOAT_POINT = "float";
	std::string PROGRAM = "program";
	std::string VARIABLES = "var";
	std::string BEGIN = "begin";
	std::string END = "end";
	std::string READ = "read";
	std::string WRITE = "write";
	// Operadores
	std::string SUMA = "+";
	std::string RESTA = "-";
	std::string MULTIPLICACION = "*";
	std::string DIVISION = "/";
	std::string ASIGNACION = "=";
	// Limitadores
	std::string DOS_PUNTOS = ":";
	std::string PUNTO_COMA = ";";
	std::string COMA = ",";

	public:
	// Constructors
	Scanner();
	Scanner(std::string codigo_fuente);	

	// Funciones Auxiliares
	std::vector<std::string> lista_palabras();
	void enlista_tokens();
	std::vector<Token> escanear();
};