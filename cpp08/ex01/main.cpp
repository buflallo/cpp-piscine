
#include "span.hpp"

int main()
{
    std::cout << "===================" << std::endl;
    std::cout << "    subject test" << std::endl;
    std::cout << "===================" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span : "<< sp.shortestSpan() << std::endl;
        std::cout << "Longest span : "<<sp.longestSpan() << std::endl;  
    }
    catch (std::exception & e)
    {
        std::cout << "No span can be found" << std::endl;
    }
    std::cout << "=============================" << std::endl;
    std::cout << "    generate 10000 numbers" << std::endl;
    std::cout << "=============================" << std::endl;
    try
    {
        Span sp1 = Span(10000);
        sp1.generate();
        // sp1 = generate(sp1, 10000);
        std::cout << "Shortest span : "<< sp1.shortestSpan() << std::endl;
        std::cout << "Longest span : "<< sp1.longestSpan() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "No span can be found" << std::endl;
    }
}