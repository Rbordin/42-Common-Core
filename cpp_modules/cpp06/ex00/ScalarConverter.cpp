#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string& str) 
{
    std::cout << std::fixed << std::setprecision(1);

    if (str.length() == 1 && isprint(str[0]) && !std::isdigit(str[0])) 
        convertChar(str[0]);
    else if (isSpecialType(str)) 
        convertSpecialType(str);
    else if (isValidNumber(str)) 
        convertNumber(str);
    else 
        std::cout << "conversion impossible" << std::endl;
}

void ScalarConverter::convertChar(char c) 
{
    int     i = static_cast<int>(c);
    float   f = static_cast<float>(c);
    double  d = static_cast<double>(c);

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f"<<std::endl;
    std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::isSpecialType(const std::string& str) 
{
    std::string specialTypes[6] = {"-inff", "+inff", "nanf","-inf", "+inf", "nan"};
    for (int i = 0; i < 6; i++) 
    {
        if (specialTypes[i] == str) 
            return true;
    }
    return false;
}

void ScalarConverter::convertSpecialType(const std::string& str) 
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nan" || str == "nanf") 
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } 
    else 
    {
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str << std::endl;
    }
}

bool ScalarConverter::isValidNumber(const std::string& str) 
{
    char*   end;
    std::strtol(str.c_str(), &end, 10);
    if (*end == '\0') 
        return true;
    else 
    {
        end = NULL;
        std::strtof(str.c_str(), &end);
        if (*end == 'f' || *end == 'F' || *end == '\0')
            return true;
        else 
        {
            end = NULL;
            std::strtod(str.c_str(), &end);
            if (*end == 'f' || *end == 'F' || *end == '\0')
                return true;
        }
    }
    return false;
}

void ScalarConverter::convertNumber(const std::string& str) 
{
    int     int_cast = atoi(str.c_str());
    float   float_cast;
    double  double_cast;

    if (str[str.length() - 1] == 'f')
    {
        float_cast = static_cast<float>(atof(str.c_str()));
        double_cast = static_cast<double>(float_cast);
    }
    else
    {
        float_cast = static_cast<float>(int_cast);
        double_cast = static_cast<double>(atof(str.c_str()));
    }
    if (isprint(int_cast)) 
        std::cout << "char: '" << static_cast<char>(int_cast) << "'" << std::endl;
    else 
        std::cout << "char: not displayable" << std::endl;

    std::cout << "int: " << int_cast << std::endl;
    std::cout << "float: " << float_cast << (std::abs(float_cast) > std::numeric_limits<float>::max() ? "" : "f") << std::endl;
    std::cout << "double: " << double_cast << (std::abs(double_cast) > std::numeric_limits<double>::max() ? "" : "") << std::endl;
}