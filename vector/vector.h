#ifndef vect
#define vect

#include <iostream>

template <typename T>
class Vector {
public:
    Vector(); //
    Vector(std::size_t s); //
    Vector(std::size_t s, T val); //
    Vector(const Vector<T>& rhv); //
    Vector(Vector<T>&& rhv); //
    ~Vector(); //
public:
    const Vector<T>& operator=(const Vector& rhv); //
    const Vector<T>& operator=(Vector&& rhv); //
    void reserve(std::size_t n); //
    std::size_t capacity() const; //
    bool include(T val) const; //
    void insert(T val, int pos); //
    void push_back(T val); //
    void pop_back(); //
    void remove(int pos); //
    void clear(); //
    std::size_t sizee() const; //
    bool isEmpty() const; //
    T& operator[](int pos); //
    void shrink_to_fit(); //
private:
    void resize(int s); //
private:
    T* arr;
    std::size_t cap;
    std::size_t size;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, Vector<T> vector);


#endif