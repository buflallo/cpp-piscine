
#include "span.hpp"

int main()
{
    Span sp = Span(5);

    try {
        sp.fill_v(5);
        print_v(sp.get_v());
        std::cout << "shortest span :" << sp.shortestSpan() << std::endl;
        std::cout << "longest span :" << sp.longestSpan() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}