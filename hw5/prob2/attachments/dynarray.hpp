#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP 1

#include <cstddef>
#include <stdexcept>

class Dynarray {
    std::size_t m_size = 0;
    int *m_storage = nullptr;
public:
    // Initialization 
    // Default constructor
    Dynarray() = default;

    // Initialize with a length (avoid implicitly conversion)
    explicit Dynarray(std::size_t n)
        : m_size(n), m_storage(new int[n]{}){}

    // Initialize with length n and value x
    Dynarray(size_t n, int x)
        : m_size(n), m_storage(new int[n]{}){
        for (std::size_t i = 0; i < n; i ++){
            m_storage[i] = x;
        }
    }

    // Initializes the object a to be an "array" of length end - begin
    Dynarray(const int *begin, const int *end)
        : m_size(end - begin), m_storage(new int[m_size]{}){
        const int *ptr = begin;
        for (std::size_t i = 0; i < m_size; i++){
            m_storage[i] = *ptr;
            ptr++;
        }
    }

    // Copy cosntructor
    Dynarray(const Dynarray &other)
        : m_size(other.size()), m_storage(new int[m_size]{}){
        for (std::size_t i = 0; i < m_size; i++){
            m_storage[i] = other.at(i);
        }
    };

    // Copy operator(version 1)
    Dynarray &operator=(const Dynarray &other){
        int *new_storage = new int[other.size()];
        for (std::size_t i = 0; i < other.size(); i++){
            new_storage[i] = other.at(i);
        }
        delete[] m_storage;
        m_size = other.size();
        m_storage = new_storage;
        return *this;
    }

    // Another possible version of copy operator

    // Dynarray &operator=(const Dynarray &other){
    //     if (this != &other){
    //         delete[] m_storage;
    //         m_size = other.size();
    //         m_storage = new int[m_size];
    //         for (auto i = 0; i < other.size(); i++)
    //         {
    //             m_storage[i] = other.at(i);
    //         }
    //     }
    //     return *this;
    // }
    // Move constructor
    Dynarray(Dynarray &&other) noexcept
        : m_size(other.m_size), m_storage(other.m_storage){
        other.m_size = 0;
        other.m_storage = nullptr;
    }

    // Move operator
    Dynarray &operator=(Dynarray &&other) noexcept {
        if (this != &other){
            delete[] m_storage;
            m_size = other.m_size;
            m_storage = other.m_storage;
            other.m_size = 0;
            other.m_storage = nullptr;
        }
        return *this;
    }

    // Destructor
    ~Dynarray() {
        delete[] m_storage;
    }

    // Basic info
    std::size_t size() const { return m_size; }
    bool empty() const { return m_size == 0u; }

    // Element access
    int &at(size_t n){
        if (n >= m_size){
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        return m_storage[n];
    }

    const int &at(size_t n) const {
        if (n >= m_size){
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        return m_storage[n];
    }
};

#endif // DYNARRAY_HPP 