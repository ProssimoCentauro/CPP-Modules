#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter constructed" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "ScalarConverter copied" << std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << "ScalarConverter assigned" << std::endl;
    if (this != &other) {
        // copy fields here
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructed" << std::endl;
}
	
bool ScalarConverter::isInt(std::string literal)
{
	size_t i = 0;

    if (literal.empty())
	{
        return false;
	}

	if (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i == literal.length())
        return false;

    while (i < literal.length())
    {
        if (literal[i] < '0' || literal[i] > '9')
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloat(std::string literal)
{
    int i;
    int dot;
    int end;

    if (literal.empty())
        return false;

    i = 0;
    dot = 0;
    end = literal.length();

    if (literal[end - 1] == 'f')
        end--;

    if (literal[i] == '+' || literal[i] == '-')
        i++;

    if (i >= end)
        return false;

    while (i < end)
    {
        if (literal[i] == '.')
        {
            if (dot)
                return false;
            dot = 1;
        }
        else if (literal[i] < '0' || literal[i] > '9')
            return false;
        i++;
    }
    return dot;
}


bool ScalarConverter::isPseudoLiteral(std::string literal)
{
    static const std::string pseudo[] = {
        "-inff", "+inff", "nanf",
        "-inf", "+inf", "nan", "inf", "inff"
    };

    for (int i = 0; i < 8; i++)
    {
        if (literal == pseudo[i])
            return true;
    }
    return false;
}

bool ScalarConverter::isChar(std::string literal)
{
	if (literal.length() != 1)
		return false;
	if (literal[0] < 33 || literal[0] > 126)
		return false;
	return true;
}

bool ScalarConverter::isValid(std::string literal)
{
	if (isInt(literal) || isFloat(literal) || isPseudoLiteral(literal) || isChar(literal))
		return 1;
	return 0;
}

void ScalarConverter::convert(std::string literal)
{
	if (!isValid(literal))
	{
		std::cerr << "Error: NO CONVERSION POSSIBLE!" << std::endl;
		return;
	}
	std::cerr << "Success: CONVERSION POSSIBLE!" << std::endl;
}









