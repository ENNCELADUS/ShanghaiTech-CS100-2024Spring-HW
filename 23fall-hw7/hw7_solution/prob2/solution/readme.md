先重点讲一个问题：如何计算两个 `Dimensions` 的乘积（即各维度相加得到的 `Dimensions`）。主要有三种方法：

1. 声明函数模板参数的时候直接把 14 个整数列出来：
   
   ```cpp
   template <typename T, int M1, int L1, int T1, int EC1, int Tmp1, int LI1, int AOS1,
                         int M2, int L2, int T2, int EC2, int Tmp2, int LI2, int AOS2>
   constexpr auto operator*(
       const Quantity<T, Dimensions<M1, L1, T1, EC1, Tmp1, LI1, AOS1>> &lhs,
       const Quantity<T, Dimensions<M2, L2, T2, EC2, Tmp2, LI2, AOS2>> &rhs) {
     using DimResult = Dimensions<M1 + M2, L1 + L2, T1 + T2, EC1 + EC2, Tmp1 + Tmp2, LI1 + LI2, AOS1 + AOS2>;
     return Quantity<T, DimResult>(lhs.value() * rhs.value());
   }
   ```
  
   写这么多整数累不累？你应该学会使用**可变参数模板**：

   ```cpp
   template <typename T, int... D1, int... D2>
   constexpr auto operator*(const Quantity<T, Dimensions<D1...>> &lhs,
                            const Quantity<T, Dimensions<D2...>> &rhs) {
     return Quantity<T, Dimensions<(D1 + D2)...>>(lhs.value() * rhs.value());
   }
   ```

   这个写法可以在 `quantity_direct.hpp` 里看到。
2. 额外写一个辅助用的**元函数**，假设叫 `DimAdd` 。我们希望可以这样使用它：
   
   ```cpp
   template <typename T, typename D1, typename D2>
   constexpr auto operator*(const Quantity<T, D1> &lhs, const Quantity<T, D2> &rhs) {
     return Quantity<T, typename DimAdd<D1, D2>::result>(lhs.value() * rhs.value());
   }
   ```

   也就是说， `DimAdd` 应当接受两个类型参数，在这两个类型都是 `Dimensions` 的实例的时候声明一个类型成员 `result` 表示这两个 `Dimensions` 各项相加得到的 `Dimensions` 。这很容易用模板偏特化实现：

   ```cpp
   template <typename, typename>
   struct DimAdd;

   template <int... D1, int... D2>
   struct DimAdd<Dimensions<D1...>, Dimensions<D2...>> {
     using result = Dimensions<(D1 + D2)...>;
   };
   ```
   
   由于这个 `DimAdd` 是我们的实现细节，它应该被塞进 `namespace detail` 里，然后在使用的时候要加上 `detail::` 。

   这个写法可以在 `quantity_metafunc.hpp` 里看到。
3. 许多同学试图提取出 `Dimensions<...>` 的各个模板参数，就像这样：
   
   ```cpp
   template <typename T, typename D1, typename D2>
   constexpr auto operator*(const Quantity<T, D1> &lhs, const Quantity<T, D2> &rhs) {
     using DimResult = Dimensions<
         D1::Mass + D2::Mass
         D1::Length + D2::Length
         D1::Time + D2::Time
         D1::ElectricCurrent + D2::ElectricCurrent
         D1::Temperature + D2::Temperature
         D1::LuminousIntensity + D2::LuminousIntensity
         D1::AmountOfSubstance + D2::AmountOfSubstance
     >;
     return Quantity<T, DimResult>(lhs.value() * rhs.value());
   }
   ```

   遗憾的是，像 `D1::Mass` 这种写法并不能用来提取模板参数，只能提取一个名为 `Mass` 的 `static` 成员或类型成员。一种补救措施就是声明一串成员来存放这些模板参数：

   ```cpp
   template <int Mass, int Length, int Time, int ElectricCurrent, int Temperature,
             int LuminousIntensity, int AmountOfSubstance>
   struct Dimensions {
     static constexpr auto mass = Mass;
     static constexpr auto length = Length;
     static constexpr auto time = Time;
     static constexpr auto electricCurrent = ElectricCurrent;
     static constexpr auto temperature = Temperature;
     static constexpr auto luminousIntensity = LuminousIntensity;
     static constexpr auto amountOfSubstance = AmountOfSubstance;
   };
   ```

   注意这些成员名字首字母是小写的，它们不可以和模板参数名同名。模板参数名不能被遮掩，它和普通变量的名字的作用域和名字查找规则是不同的。然后你通过 `D1::mass` 来取这些成员即可。

在 `quantity_mixed_arith.hpp` 里你可以看到允许混用不同算术类型的方式。题目里提示使用 `std::common_type` ，实际上它不够好。最好的办法是类似于 `decltype(lhs.value() * rhs.value())` ，即直接使用 `lhs.value() * rhs.value()` 这个乘积的结果类型作为两个 `Quantity` 的乘积的结果类型，乘出来是啥就是啥。

最后提一下如何引入单位。可以参考 [`std::chrono::duration`](https://en.cppreference.com/w/cpp/chrono/duration) 的做法，借助[编译期有理数 `std::ratio`](https://en.cppreference.com/w/cpp/numeric/ratio/ratio) 来实现，大概类似于

```cpp
template <typename T, typename Dim, typename Unit = std::ratio<1>>
class Quantity {
  // ...
};
```

其中 `Unit` 应当是一个 `std::ratio` 的实例。然后你定义各个运算的时候需要小心，比如毫秒和秒可以相加，结果是毫秒；毫秒可以 `+=` 秒，但是秒不能 `+=` 毫秒。有兴趣的话翻翻标准库，看看 `chrono` 里是怎样定义这些运算的。