#include <iostream>

template<typename T>

void iter(T a[], int const & b, void  func(const T &))
{
    int i = 0;
    while (i < b)
    {
        func(a[i]);
        i++;
    }
}


class Awesome
{ 
    public:
        Awesome(void):_n(42) {}
        Awesome ( int n ):_n(n) {}
        Awesome & operator= (Awesome & a) { _n = a. _n; return *this; }
        int get() const { return _n; }
    private:
        int _n;
};

template<typename T>
void print(T const &a)
{
    std::cout << a << std::endl;
}
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get(); return o; }

int main(void)
{
    int tab[] = { 0,1,2,3,4 };
    Awesome tab2[5];

    iter(tab, 5 , print);
    iter (tab2 ,5 , print);
return (0);
}