// Class Token
#include <utility> // pair
#include <string> // string
#include <iostream>

class Token {
	private:
	std::string tipo_token;
	std::string data;
	int index;

	public:
	Token();
	Token(std::string tipo_token, std::string data, int index);
	void print();
};