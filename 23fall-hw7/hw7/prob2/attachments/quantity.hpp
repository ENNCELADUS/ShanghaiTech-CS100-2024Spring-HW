#ifndef QUANTITY_HPP
#define QUANTITY_HPP

template <int Mass, int Length, int Time, int ElectricCurrent, int Temperature,
          int LuminousIntensity, int AmountOfSubstance>
struct Dimensions {};

namespace detail {

template <typename T> inline constexpr auto isDimensions = false;

template <int M, int L, int T, int EC, int Tmp, int LI, int AOS>
inline constexpr auto isDimensions<Dimensions<M, L, T, EC, Tmp, LI, AOS>> =
    true;

} // namespace detail

template <typename T, typename Dim> class Quantity {
  static_assert(detail::isDimensions<Dim>);

  T mValue;

public:
  constexpr explicit Quantity(const T &x) : mValue{x} {}

  constexpr const T &value() const { return mValue; }

  // TODO: Add other operators
};

// TODO: Add other operators

// TODO: Add 'pow' and 'sqrt' support

template <typename T>
using Scalar = Quantity<T, Dimensions<0, 0, 0, 0, 0, 0, 0>>;
template <typename T>
using Mass = Quantity<T, Dimensions<1, 0, 0, 0, 0, 0, 0>>;
template <typename T>
using Length = Quantity<T, Dimensions<0, 1, 0, 0, 0, 0, 0>>;
template <typename T>
using Time = Quantity<T, Dimensions<0, 0, 1, 0, 0, 0, 0>>;
template <typename T>
using ElectricCurrent = Quantity<T, Dimensions<0, 0, 0, 1, 0, 0, 0>>;
template <typename T>
using Temperature = Quantity<T, Dimensions<0, 0, 0, 0, 1, 0, 0>>;
template <typename T>
using LuminousIntensity = Quantity<T, Dimensions<0, 0, 0, 0, 0, 1, 0>>;
template <typename T>
using AmountOfSubstance = Quantity<T, Dimensions<0, 0, 0, 0, 0, 0, 1>>;

#endif // QUANTITY_HPP