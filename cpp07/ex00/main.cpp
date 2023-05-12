#include <iostream>

template<typename T>

void swap(T& a, T& b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T max(const T& a, const T& b)
{
    return a > b ? a : b;
}

template<typename T>
T min(const T& a, const T& b)
{
    return a < b ? a : b;
}


class Awesome
{ 
    public:
        Awesome(void):_n(0) {}
        Awesome ( int n ):_n(n) {}
        Awesome & operator= (Awesome & a) { _n = a. _n; return *this; }
        bool operator== ( Awesome const & rhs ) const { return (this->_n == rhs. _n); }
        bool operator!= ( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
        bool operator> ( Awesome const & rhs ) const { return (this->_n > rhs. _n); }
        bool operator< (Awesome const & rhs ) const { return (this->_n < rhs._n); }
        bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n) ;}
        bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
        int get_n() const { return _n; }
    private:
        int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
    Awesome a(2), b(4);
    swap (a, b);
    std::cout << a << "'" << b << std::endl;
    std::cout << max(a, b);
    std::cout << min(a, b) << std::endl;
    return (0);
}