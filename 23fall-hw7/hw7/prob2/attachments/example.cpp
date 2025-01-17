#include <iostream>
#include <type_traits>

#include "quantity.hpp"

template <typename T>
using Acceleration = Quantity<T, Dimensions<0, 1, -2, 0, 0, 0, 0>>;

int main() {
  Acceleration<double> g(9.8);
  Time<double> t(42.0);
  auto h = Scalar<double>(0.5) * g * pow<2>(t);
  static_assert(std::is_same_v<decltype(h), Length<double>>);
  std::cout << h.value() << std::endl;
  auto t_2 = sqrt(Scalar<double>(2.0) * h / g);
  static_assert(std::is_same_v<decltype(t_2), Time<double>>);
  std::cout << t_2.value() << std::endl;
  return 0;
}