#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>

template<typename T>
typename T::iterator easyfind(T &container, int n);

# include "easyfind.tpp"

#endif