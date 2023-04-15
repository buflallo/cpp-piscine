#include "ScalarConverter.hpp"

void isDigits(std::string str)
{
    size_t i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    if (!str[i])
        throw std::out_of_range("value of int: impossible\nvalue of float: impossible\nvalue of double: impossible");
    while (str[i])
    {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.' && str.find_last_of('.') == (i)) || (str[i] == 'f' && !str[i+1]))
            i++;
        else
            break;
    }
    if (str[i])
        throw std::out_of_range("value of int: impossible\nvalue of float: impossible\nvalue of double: impossible");
}

void isChar(int c)
{
    if (c > std::numeric_limits<char>::max() || c < std::numeric_limits<char>::min())
        throw "value of char: impossible";
    else if (!isprint(c))
        throw "value of char: non diplayable";
}

void isInt(double x)
{
    if (x > std::numeric_limits<int>::max() || x < std::numeric_limits<int>::min())
        throw std::out_of_range("value of int: impossible");
}

void isFloat(double x)
{
    if (x > std::numeric_limits<float>::max() || x < std::numeric_limits<float>::min())
        throw std::out_of_range("value of float: impossible");

}

void isDouble(long double x)
{
    if (x > std::numeric_limits<double>::max() || x < std::numeric_limits<double>::min())
        throw std::out_of_range("value of double: impossible");
}

void print_char(std::string val)
{
    int save;
    try
    {
        save = stoi(val); // exception a, qwwq | not 2121, 2
        isChar(save); // exception2 323232, 9, 0, | not 32, 126
        isDigits(val);
        std::cout << "value of char: '" << static_cast<char>(save) << "'" << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        if (val.length() == 1)
        {
            std::cout << "value of char: '" << static_cast<char>(val[0]) << "'" << std::endl;
        }
        std::cout << "value of char: impossible" << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        //exceptions to handle a, qwwq,  323232, 9, 0, 
        std::cout << "value of char: impossible" << std::endl;
    }
    catch (char const* e)
    {
        std::cout << e << std::endl;
    }
}

void print_errors(std::string val, const std::out_of_range& e)
{
    if (val == "nan" || val == "+inf" || val == "-inf")
    {
        std::cout << "value of int: impossible" << std::endl;
        std::cout << "value of float: " << val << "f" << std::endl;
        std::cout << "value of double: " << val << std::endl;
    }
    else
    {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverter::convert(std::string val)
{
    print_char(val);
    try{
        isDigits(val);
        double save = stod(val);
        try{
            isInt(save);
            std::cout << "value of int: " << static_cast<int>(save) << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "value of int: impossible" << std::endl;
        }
        try{
            isFloat(save);
            std::cout << "value of float: " << static_cast<float>(save) << "f" << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "value of float: impossible" << std::endl;
        }
        try{
            isDouble(stold(val));
            std::cout << "value of double: " <<  static_cast<double>(stold(val)) << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "value of double: impossible" << std::endl;
        }
    }
    catch (const std::out_of_range& e)
    {
        print_errors(val, e);
    }
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const& obj)
{
    (void) obj;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    (void) rhs;
    return *this;
}
