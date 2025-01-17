#ifndef QUANTITY_HPP
#define QUANTITY_HPP

#include <cmath>

template <int Mass, int Length, int Time, int ElectricCurrent, int Temperature,
          int LuminousIntensity, int AmountOfSubstance>
struct Dimensions {};

namespace detail {

template <typename T> inline constexpr auto isDimensions = false;

template <int... Ds>
inline constexpr auto isDimensions<Dimensions<Ds...>> = true;

template <typename, typename> struct DimPlus;

template <int... D1, int... D2>
struct DimPlus<Dimensions<D1...>, Dimensions<D2...>> {
  using result = Dimensions<(D1 + D2)...>;
};

template <typename, typename> struct DimMinus;

template <int... D1, int... D2>
struct DimMinus<Dimensions<D1...>, Dimensions<D2...>> {
  using result = Dimensions<(D1 - D2)...>;
};

template <typename, int> struct DimScale;

template <int... Ds, int Power> struct DimScale<Dimensions<Ds...>, Power> {
  using result = Dimensions<(Ds * Power)...>;
};

template <typename> struct DimHalf;

template <int... Ds> struct DimHalf<Dimensions<Ds...>> {
  static_assert(((Ds % 2 == 0) && ...),
                "For 'sqrt', the dimensions must be a multiple of 2!");
  using result = Dimensions<(Ds / 2)...>;
};

} // namespace detail

template <typename T, typename Dim> class Quantity {
  static_assert(detail::isDimensions<Dim>);

  T mValue;

public:
  constexpr explicit Quantity(const T &x) : mValue{x} {}

  constexpr const T &value() const { return mValue; }

  constexpr Quantity &operator+=(const Quantity &rhs) {
    mValue += rhs.value();
    return *this;
  }

  constexpr Quantity &operator-=(const Quantity &rhs) {
    mValue -= rhs.value();
    return *this;
  }

  constexpr Quantity &
  operator*=(const Quantity<T, Dimensions<0, 0, 0, 0, 0, 0, 0>> &scalar) {
    mValue *= scalar.value();
    return *this;
  }

  constexpr Quantity &
  operator/=(const Quantity<T, Dimensions<0, 0, 0, 0, 0, 0, 0>> &scalar) {
    mValue /= scalar.value();
    return *this;
  }

  constexpr Quantity operator+(const Quantity &rhs) const {
    return Quantity(value() + rhs.value());
  }

  constexpr Quantity operator-(const Quantity &rhs) const {
    return Quantity(value() - rhs.value());
  }

  constexpr Quantity operator-() const { return Quantity(-value()); }

  constexpr Quantity operator+() const { return Quantity(+value()); }
};

template <typename T, typename D1, typename D2>
constexpr auto operator*(const Quantity<T, D1> &lhs,
                         const Quantity<T, D2> &rhs) {
  return Quantity<T, typename detail::DimPlus<D1, D2>::result>(lhs.value() *
                                                               rhs.value());
}

template <typename T, typename D1, typename D2>
constexpr auto operator/(const Quantity<T, D1> &lhs,
                         const Quantity<T, D2> &rhs) {
  return Quantity<T, typename detail::DimMinus<D1, D2>::result>(lhs.value() /
                                                                rhs.value());
}

template <int Power, typename T, typename D>
constexpr auto pow(const Quantity<T, D> &x) {
  return Quantity<T, typename detail::DimScale<D, Power>::result>(
      std::pow(x.value(), Power));
}

template <typename T, typename D> constexpr auto sqrt(const Quantity<T, D> &x) {
  return Quantity<T, typename detail::DimHalf<D>::result>(std::sqrt(x.value()));
}

template <typename T>
using Scalar = Quantity<T, Dimensions<0, 0, 0, 0, 0, 0, 0>>;
template <typename T> using Mass = Quantity<T, Dimensions<1, 0, 0, 0, 0, 0, 0>>;
template <typename T>
using Length = Quantity<T, Dimensions<0, 1, 0, 0, 0, 0, 0>>;
template <typename T> using Time = Quantity<T, Dimensions<0, 0, 1, 0, 0, 0, 0>>;
template <typename T>
using ElectricCurrent = Quantity<T, Dimensions<0, 0, 0, 1, 0, 0, 0>>;
template <typename T>
using Temperature = Quantity<T, Dimensions<0, 0, 0, 0, 1, 0, 0>>;
template <typename T>
using LuminousIntensity = Quantity<T, Dimensions<0, 0, 0, 0, 0, 1, 0>>;
template <typename T>
using AmountOfSubstance = Quantity<T, Dimensions<0, 0, 0, 0, 0, 0, 1>>;

#endif // QUANTITY_HPP