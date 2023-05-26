
#include "span.hpp"

int main()
{
    Span sp = Span(20);

    try {
        sp.generate(2);
        sp.generate(8);
        std::cout << "shortest span :" << sp.shortestSpan() << std::endl;
        std::cout << "longest span :" << sp.longestSpan() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}