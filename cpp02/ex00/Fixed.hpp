#include <iostream>
#include <string>

class Fixed
{
    private:
        int                 fixedPointValue;
        static const int    fractionalBits = 8;
    public:
        Fixed( void );
        Fixed( Fixed const & src );
        ~Fixed( void );
        Fixed & operator=( Fixed const & rhs );
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};