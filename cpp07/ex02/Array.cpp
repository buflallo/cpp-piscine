#include <iostream>
template<typename T>
class Array {
private:
    T* m_data; // pointeur vers le tableau de données
    size_t m_size; // taille du tableau

public:
    // constructeur par défaut
    Array() : m_data(nullptr), m_size(0) {}

    // constructeur avec taille initiale
    Array(size_t size) : m_data(new T[size]), m_size(size) {}

    // destructeur
    ~Array() {
        delete[] m_data;
    }

    // opérateur d'accès au i-ème élément du tableau
    T& operator[](size_t i) {
        return m_data[i];
    }

    // méthode pour obtenir la taille du tableau
    size_t size() const {
        return m_size;
    }
};

int main()
{
    Array<int> arr(10); // create an array of three std::string objects

    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}