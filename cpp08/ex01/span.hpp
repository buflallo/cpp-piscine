
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>
#include <cctype>
#include <random>

using u32    = uint_least32_t; 
using engine = std::mt19937;

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _v;
    public:
        Span();
        Span(unsigned int n);
        Span(Span const & src);
        ~Span();
        Span & operator=(Span const & rhs);
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void generate(void);
};


#endif