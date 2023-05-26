
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
    int s_span;
    std::vector<int>::iterator it;
    std::vector<int> v_tmp(this->_v);

    std::sort(v_tmp.begin(), v_tmp.end());
    it = v_tmp.begin();
    s_span = *(it+1) - *it;
    while ((it++)+1 != v_tmp.end() - 1)
    {
        if (s_span > *(it+1) - *it)
            s_span = *(it+1) - *it;
    }
    return s_span;
}

int Span::longestSpan()
{
    if (this->_v.size() < 2)
        throw std::out_of_range("Span is too short");
    std::vector<int> v_tmp(this->_v);

    std::sort(v_tmp.begin(), v_tmp.end());
    return *(v_tmp.end() - 1) - *v_tmp.begin();
}

static int my_rand()
{
    return rand() % 100;
}

std::vector<int> const & Span::get_v()
{
    return static_cast<std::vector<int> const &>(_v);
}

void Span::fill_v(int n)
{
    if (this->_v.size() + n > this->_n)
        throw std::out_of_range("Span can't fill elements");
    std::vector<int> v_tmp(n);

    srand(time(NULL));
    std::generate(v_tmp.begin(), v_tmp.end(), my_rand);
    _v.insert(_v.begin() , v_tmp.begin(), v_tmp.end());
}

void print_v(std::vector<int> v)
{
    std::vector<int>::iterator it;

    it = v.begin();
    while (it != v.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}
