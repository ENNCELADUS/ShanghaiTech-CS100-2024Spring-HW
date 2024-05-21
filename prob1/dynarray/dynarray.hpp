#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP 1

#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Dynarray {

// Type alias
public:
    using size_type = std::size_t;
    using value_type = int;
    using pointer = int *;
    using reference = int &;
    using const_pointer = const int *;
    using const_reference = const int &;

private:    
    size_type m_size = 0;
    pointer m_storage = nullptr;

public:
    // Initialization
    Dynarray() = default;

    explicit Dynarray(size_type n)
        : m_size(n), m_storage(new value_type[n]{}){}

    Dynarray(size_type n, value_type x)
        : m_size(n), m_storage(new value_type[n]{}) {
        std::fill(m_storage, m_storage + n, x);
    }

    Dynarray(const_pointer begin, const_pointer end)
        : m_size(end - begin), m_storage(new value_type[m_size]{}) {
        std::copy(begin, end, m_storage);
    }

    Dynarray(const Dynarray &other)
        : m_size(other.size()), m_storage(new value_type[m_size]{}) {
        std::copy(other.m_storage, other.m_storage + m_size, m_storage);
    }

    Dynarray &operator=(const Dynarray &other) {
        if (this != &other) {
            pointer new_storage = new value_type[other.size()];
            std::copy(other.m_storage, other.m_storage + other.size(), new_storage);
            delete[] m_storage;
            m_size = other.size();
            m_storage = new_storage;
        }
        return *this;
    }

    Dynarray(Dynarray &&other) noexcept
        : m_size(other.m_size), m_storage(other.m_storage) {
        other.m_size = 0;
        other.m_storage = nullptr;
    }

    Dynarray &operator=(Dynarray &&other) noexcept {
        if (this != &other) {
            delete[] m_storage;
            m_size = other.m_size;
            m_storage = other.m_storage;
            other.m_size = 0;
            other.m_storage = nullptr;
        }
        return *this;
    }

    ~Dynarray() {
        delete[] m_storage;
    }


    // Basic info
    size_type size() const { return m_size; }
    bool empty() const { return m_size == 0u; }

    reference at(size_type n) {
        if (n >= m_size) {
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        return m_storage[n];
    }

    const_reference at(size_type n) const {
        if (n >= m_size) {
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        return m_storage[n];
    }

    reference operator[](size_type i) {
        return m_storage[i];
    }

    const_reference operator[](size_type i) const {
        return m_storage[i];
    }

    // Relational operators
    friend bool operator<(const Dynarray &, const Dynarray &);
    friend bool operator==(const Dynarray &, const Dynarray &);
    friend bool operator<=(const Dynarray &, const Dynarray &);
    friend bool operator>(const Dynarray &, const Dynarray &);
    friend bool operator>=(const Dynarray &, const Dynarray &);
    friend bool operator!=(const Dynarray &, const Dynarray &);

    // Output operator
    friend std::ostream &operator<<(std::ostream &, const Dynarray &);
};

bool operator<(const Dynarray &lhs, const Dynarray &rhs){
    return std::lexicographical_compare(lhs.m_storage, lhs.m_storage + lhs.m_size, rhs.m_storage, rhs.m_storage + rhs.m_size);
}

bool operator>(const Dynarray &lhs, const Dynarray &rhs){
    return rhs < lhs;
}

bool operator<=(const Dynarray &lhs, const Dynarray &rhs){
    return !(lhs > rhs);
}

bool operator>=(const Dynarray &lhs, const Dynarray &rhs){
    return !(lhs < rhs);
}

bool operator==(const Dynarray &lhs, const Dynarray &rhs){
    return std::equal(lhs.m_storage, lhs.m_storage + lhs.m_size, rhs.m_storage, rhs.m_storage + rhs.m_size);
}

bool operator!=(const Dynarray &lhs, const Dynarray &rhs){
    return !(lhs == rhs);
}

// Output operator
std::ostream& operator<<(std::ostream &os, const Dynarray &arr){
    os << '[';
    if (!arr.empty()){
        for (Dynarray::size_type i = 0; i < arr.m_size; i++){
            os << arr[i];
            if(i != arr.m_size - 1){
                os << ',' << ' ';
            }
        }
    }
    os << ']';
    return os;
}


#endif // DYNARRAY_HPP 