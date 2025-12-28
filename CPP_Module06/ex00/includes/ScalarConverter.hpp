#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

	static bool isInt(std::string literal);
	static bool isFloat(std::string literal);
	static int isPseudoLiteral(std::string literal, const std::string pseudo[]);
	static bool isChar(std::string literal);
	static bool isValid(std::string literal, const std::string pseudo[]);
	static void printConvertion(int pseudo_index, std::string literal, const std::string pseudo[]);

public:

	static void convert(std::string literal);

};

#endif
