
#include "span.hpp"

Span::Span() : _n(0) 
{
}

Span::Span(unsigned int n) : _n(n)
{
    _v.reserve(n);
}

Span::Span(Span const & src) 
{
    *this = src;
}

Span::~Span()
{
}

Span & Span::operator=(Span const & rhs) 
{
    if (this != &rhs)
    {
        this->_n = rhs._n;
        this->_v = rhs._v;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (this->_v.size() == this->_n)
        throw std::out_of_range("Span is full");
    this->_v.push_back(n);
}

int Span::shortestSpan()
{
    if (this->_v.size() < 2)
        throw std::out_of_range("Span is too short");
    std::vector<int> v_tmp = this->_v;
    std::sort(v_tmp.begin(), v_tmp.end());
    std::vector<int>::iterator it = v_tmp.begin();
    std::vector<int>::iterator it_sec = v_tmp.begin()+1;
    int s_span = *it_sec - *it;
    while (it_sec != v_tmp.end() - 1)
    {
        it++;
        it_sec++;
        if (s_span > *it_sec - *it)
            s_span = *it_sec - *it;
    }
    return s_span;
}

int Span::longestSpan()
{
    if (this->_v.size() < 2)
        throw std::out_of_range("Span is too short");
    std::vector<int> v_tmp = this->_v;
    std::sort(v_tmp.begin(), v_tmp.end());
    std::vector<int>::iterator it = v_tmp.begin();
    std::vector<int>::iterator it_end = v_tmp.end() - 1;
    return *it_end - *it;
}

int my_rand()
{
    return rand() % 100;
}

void Span::fill_v(int n)
{
    if (this->_v.size() + n > this->_n)
        throw std::out_of_range("Span is full");
    std::vector<int> v_tmp(n);
    srand(time(NULL));
    std::generate(v_tmp.begin(), v_tmp.end(), my_rand);
    _v.insert(_v.begin() , v_tmp.begin(), v_tmp.end());
}
