// Class Scanners - Analizador Lexico
#include "Token.h"
#include <vector>
#include <string>

//Inicializacion de la clase Scanner
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

	// Funciones Auxiliares
	bool es_numero(std::string lexema);
	bool lexema_reservado(std::string lexema);
	bool caracter_reservado(char c);
	void asignar_caracter(char c);
	std::vector<std::string> lista_palabras();
	void enlista_tokens();

	public:
	// Constructores
	Scanner();
	Scanner(std::string codigo_fuente);	
	std::vector<Token> escanear();
};