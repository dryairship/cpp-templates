#include <cstdint>

template <std::uint32_t N>
class UInt32Printer;

template <std::uint32_t N>
struct FibonacciImpl
{
    static constexpr std::uint32_t theSubSequenceSum = 
            FibonacciImpl<N-1>::theSubSequenceSum + 
            FibonacciImpl<N-2>::theSubSequenceSum;
    UInt32Printer<theSubSequenceSum> thePrinter;
};

template <>
struct FibonacciImpl<1>
{
    UInt32Printer<1> thePrinter;
    static constexpr std::uint32_t theSubSequenceSum = 1;
};

template <>
struct FibonacciImpl<0>
{
    static constexpr std::uint32_t theSubSequenceSum = 0;
};

template <std::uint32_t N>
class Fibonacci
{
    static constexpr FibonacciImpl<N> theImpl{};
};

int main()
{
    Fibonacci<10>{};
    return 0;
}