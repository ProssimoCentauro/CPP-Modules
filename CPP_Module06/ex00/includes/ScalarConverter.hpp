#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

	static bool isInt(std::string literal);
	static bool isFloat(std::string literal);
	static bool isPseudoLiteral(std::string literal);
	static bool isChar(std::string literal);
	static bool isValid(std::string literal);
	//static void printConvertion(std::string literal);

public:

	static void convert(std::string literal);

};

#endif
