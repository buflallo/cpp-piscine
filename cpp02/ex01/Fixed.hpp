#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int                 fixedPointValue;
        static const int    fractionalBits = 8;
    public:
        Fixed( void );
        Fixed( int const );
        Fixed( float const );
        Fixed( Fixed const & src );
        ~Fixed( void );
        Fixed & operator=( Fixed const & rhs );
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream &  operator<<( std::ostream & out, Fixed const & f );