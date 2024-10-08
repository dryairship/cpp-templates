#include <cstdint>

template <std::uint32_t N>
class UInt32Printer;

template <std::uint32_t N>
struct FactorialImpl
{
    static constexpr FactorialImpl<N-1> theSubFactorial{};
    static constexpr std::uint32_t theResult = N * theSubFactorial.theResult;
};

template <>
struct FactorialImpl<0>
{
    static constexpr std::uint32_t theResult = 1;
};

template <std::uint32_t N>
class Factorial
{
    static constexpr FactorialImpl<N> theImpl{};
    UInt32Printer<theImpl.theResult> thePrinter;
};

int main()
{
    Factorial<6>{};
    return 0;
}