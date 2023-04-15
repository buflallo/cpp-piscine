#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <exception>

class ScalarConverter {
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const& obj);
        ScalarConverter & operator=(ScalarConverter const & rhs);
        static void convert(std::string val);
};