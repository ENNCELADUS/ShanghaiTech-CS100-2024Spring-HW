#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP 1

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class Dynarray
{
  static_assert(!std::is_const_v<T> && !std::is_volatile_v<T>,
                "Dynarray must have a non-const, non-volatile value type.");
  static_assert(!std::is_reference_v<T>,
                "Dynarray value type must not be a reference.");

public:
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  using const_pointer = const T *;
  using const_reference = const T &;
  using iterator = pointer;
  using const_iterator = const_pointer;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

private:
  size_type m_length;
  pointer m_storage;

public:
  explicit Dynarray(size_type n)
      : m_length{n}, m_storage{new value_type[n]{}} {}
  Dynarray(size_type n, const value_type &x)
      : m_length{n}, m_storage{new value_type[n]}
  {
    std::fill_n(m_storage, n, x);
  }
  Dynarray() : m_length{0}, m_storage{nullptr} {}
  template <typename ForwardIter,
            typename = std::enable_if_t<std::is_base_of_v<
                std::forward_iterator_tag,
                typename std::iterator_traits<ForwardIter>::iterator_category>>>
  Dynarray(ForwardIter begin, ForwardIter end)
      : m_length(std::distance(begin, end)),
        m_storage{new value_type[m_length]}
  {
    std::copy(begin, end, m_storage);
  }
  Dynarray(const Dynarray &other)
      : m_length{other.size()}, m_storage{new value_type[m_length]}
  {
    std::copy_n(other.m_storage, other.m_length, m_storage);
  }
  Dynarray(Dynarray &&other) noexcept
      : m_length{std::exchange(other.m_length, 0)},
        m_storage{std::exchange(other.m_storage, nullptr)} {}
  void swap(Dynarray &other) noexcept
  {
    using std::swap;
    swap(m_length, other.m_length);
    swap(m_storage, other.m_storage);
  }
  Dynarray &operator=(Dynarray other) noexcept
  {
    swap(other);
    return *this;
  }
  ~Dynarray() { delete[] m_storage; }

  iterator begin() { return m_storage; }
  iterator end() { return m_storage + m_length; }
  const_iterator cbegin() const { return m_storage; }
  const_iterator cend() const { return m_storage + m_length; }
  const_iterator begin() const { return cbegin(); }
  const_iterator end() const { return cend(); }
  reverse_iterator rbegin() { return reverse_iterator(end()); }
  reverse_iterator rend() { return reverse_iterator(begin()); }
  const_reverse_iterator crbegin() const
  {
    return const_reverse_iterator(cend());
  }
  const_reverse_iterator crend() const
  {
    return const_reverse_iterator(cbegin());
  }
  const_reverse_iterator rbegin() const { return crbegin(); }
  const_reverse_iterator rend() const { return crend(); }

  size_type size() const { return m_length; }
  bool empty() const { return m_length == 0u; }
  reference at(size_type n)
  {
    return const_cast<reference>(static_cast<const Dynarray *>(this)->at(n));
  }
  const_reference at(size_type n) const
  {
    if (n >= m_length)
      throw std::out_of_range{"Dynarray index out of range."};
    return m_storage[n];
  }
  reference operator[](size_type n) { return m_storage[n]; }
  const_reference operator[](size_type n) const { return m_storage[n]; }

  friend bool operator==(const Dynarray &lhs, const Dynarray &rhs)
  {
    return std::equal(lhs.m_storage, lhs.m_storage + lhs.m_length,
                      rhs.m_storage, rhs.m_storage + rhs.m_length);
  }
  friend bool operator<(const Dynarray &lhs, const Dynarray &rhs)
  {
    return std::lexicographical_compare(
        lhs.m_storage, lhs.m_storage + lhs.m_length, rhs.m_storage,
        rhs.m_storage + rhs.m_length);
  }
};

template <typename T>
bool operator!=(const Dynarray<T> &lhs, const Dynarray<T> &rhs)
{
  return !(lhs == rhs);
}

template <typename T>
bool operator>(const Dynarray<T> &lhs, const Dynarray<T> &rhs)
{
  return rhs < lhs;
}

template <typename T>
bool operator<=(const Dynarray<T> &lhs, const Dynarray<T> &rhs)
{
  return !(lhs > rhs);
}

template <typename T>
bool operator>=(const Dynarray<T> &lhs, const Dynarray<T> &rhs)
{
  return !(lhs < rhs);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Dynarray<T> &a)
{
  os << '[';
  if (!a.empty())
  {
    os << a[0];
    for (std::size_t i = 1; i < a.size(); ++i)
      os << ", " << a[i];
  }
  return os << ']';
}

template <typename ForwardIter>
Dynarray(ForwardIter, ForwardIter)
    -> Dynarray<typename std::iterator_traits<ForwardIter>::value_type>;

#endif // DYNARRAY_HPP