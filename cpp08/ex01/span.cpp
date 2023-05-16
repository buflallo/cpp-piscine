
#include "span.hpp"

Span::Span() : _n(0) 
{
    // std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
    _v.reserve(n);
    // std::cout << "Constructor called" << std::endl;
}

Span::Span(Span const & src) 
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Span::~Span() 
{
    // std::cout << "Destructor called" << std::endl;
}

Span & Span::operator=(Span const & rhs) 
{
    // std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_n = rhs._n;
        this->_v = rhs._v;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (this->_v.size() < this->_n)
        this->_v.push_back(n);
    else
        throw std::exception();
}

int Span::shortestSpan()
{
    if (this->_v.size() < 2)
        throw std::exception();
    int min = *_v.begin();
    
    return min2 - min;
}

int Span::longestSpan()
{
    if (this->_v.size() < 2)
        throw std::exception();
    std::vector<int> v = this->_v;
    std::sort(v.begin(), v.end());
    return v[v.size() - 1] - v[0];
}

void Span::generate(void)
{
    std::vector<int>::iterator it = this->_v.begin();
    srand(time(NULL));
    for (size_t i = 0; i < (size_t)_v.capacity(); i++)
    {
        *it = rand() % 10000;
        _v.insert(it, *it);
        it++;
    }
}
