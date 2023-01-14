#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <exception>


std::error_code stod(std::nothrow_t) noexcept;
std::error_code stold(std::nothrow_t) noexcept;
std::error_code stoi(std::nothrow_t) noexcept;

// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0

void isDigits(std::string str)
{
    int i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i])
    {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.' && str.find_last_of('.') == i) || (str[i] == 'f' && !str[i+1]))
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
        throw std::out_of_range("value of char: impossible");
    else if (!isprint(c))
        throw std::out_of_range("value of char: impossible");
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
        std::cout << "value of char: " << static_cast<char>(save) << std::endl;
    }
    catch (const std::exception& e)
    {
        //exceptions to handle a, qwwq,  323232, 9, 0, 
        if (val.length() > 1)
            std::cout << "value of char: impossible" << std::endl;
        else
        {
            std::cout << "value of char: " << static_cast<char>(val[0]) << std::endl;
        }
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

void print(std::string val)
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

int main(int ac, char **av)
{
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    print(av[1]);
}