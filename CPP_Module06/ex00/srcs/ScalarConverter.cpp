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
    size_t i;
    size_t end;
    int dot;
    int digit_before;
    int digit_after;

    if (literal.empty())
        return false;

    i = 0;
    dot = 0;
    digit_before = 0;
    digit_after = 0;
    end = literal.length();

    if (literal[end - 1] == 'f')
        end--;

    if (i >= end)
        return false;

    if (literal[i] == '+' || literal[i] == '-')
        i++;

    while (i < end)
    {
        if (literal[i] >= '0' && literal[i] <= '9')
        {
            if (!dot)
                digit_before = 1;
            else
                digit_after = 1;
        }
        else if (literal[i] == '.')
        {
            if (dot)
                return false;
            dot = 1;
        }
        else
            return false;
        i++;
    }

    return (dot && digit_before && digit_after);
}

int ScalarConverter::isPseudoLiteral(std::string literal, const std::string pseudo[])
{

	for (int i = 0; i < 8; i++)
	{
		if (literal == pseudo[i])
			return (i + 1);
	}
	return (-1);
}

bool ScalarConverter::isChar(std::string literal)
{
	if (literal.length() != 1)
		return false;
	if (literal[0] < 32 || literal[0] > 126)
		return false;
	return true;
}

bool ScalarConverter::isValid(std::string literal, const std::string pseudo[])
{
	if (isInt(literal)
			|| isFloat(literal)
			|| isChar(literal)
			|| isPseudoLiteral(literal, pseudo) > 0)
		return true;
	return false;
}

void ScalarConverter::printConvertion(int pseudo_index, std::string literal, const std::string pseudo[])
{
    double num = 0.0;
    bool literalIsChar = isChar(literal);

    pseudo_index -= 1;

    if (!literalIsChar && pseudo_index == -2)
        num = std::strtod(literal.c_str(), NULL);

    /* CHAR */
    if (literalIsChar)
        std::cout << "char: '" << literal[0] << "'" << std::endl;
    else if (pseudo_index != -2)
        std::cout << "char: impossible" << std::endl;
    else if (num < 0 || num > 127)
        std::cout << "char: impossible" << std::endl;
    else if (num < 32 || num > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;

    /* INT */
    if (literalIsChar)
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
    else if (pseudo_index != -2)
        std::cout << "int: impossible" << std::endl;
    else if (num < -2147483648.0 || num > 2147483647.0)
        std::cout << "int: overflow or underflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;

    /* FLOAT */
    if (pseudo_index >= 0 && pseudo_index <= 3)
        std::cout << "float: " << pseudo[pseudo_index + 4] << std::endl;
    else if (pseudo_index >= 4 && pseudo_index <= 7)
        std::cout << "float: " << pseudo[pseudo_index] << std::endl;
    else
    {
        float f = literalIsChar ? static_cast<float>(literal[0]) : static_cast<float>(num);
        std::cout << "float: " << f;
        if (f == static_cast<long>(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }

    /* DOUBLE */
    if (pseudo_index >= 0 && pseudo_index <= 3)
        std::cout << "double: " << pseudo[pseudo_index] << std::endl;
    else if (pseudo_index >= 4 && pseudo_index <= 7)
        std::cout << "double: " << pseudo[pseudo_index - 4] << std::endl;
    else
    {
        double d = literalIsChar ? static_cast<double>(literal[0]) : num;
        std::cout << "double: " << d;
        if (d == static_cast<long>(d))
            std::cout << ".0";
        std::cout << std::endl;
    }
}


void ScalarConverter::convert(std::string literal)
{
    static const std::string pseudo[] = {
        "-inff", "+inff", "inff", "nanf",
        "-inf", "+inf", "inf", "nan"
    };

	if (!isValid(literal, pseudo))
	{
		std::cerr << "Error: NO CONVERSION POSSIBLE!" << std::endl;
		return;
	}
	printConvertion(isPseudoLiteral(literal, pseudo), literal, pseudo);
}









