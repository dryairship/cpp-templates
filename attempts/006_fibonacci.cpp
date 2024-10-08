template <int N>
class IntPrinter;

template <int N>
struct FibonacciImpl
{
    static constexpr int theSubSequenceSum = 
            FibonacciImpl<N-1>::theSubSequenceSum + 
            FibonacciImpl<N-2>::theSubSequenceSum;
    IntPrinter<theSubSequenceSum> thePrinter;
};

template <>
struct FibonacciImpl<1>
{
    IntPrinter<1> thePrinter;
    static constexpr int theSubSequenceSum = 1;
};

template <>
struct FibonacciImpl<0>
{
    static constexpr int theSubSequenceSum = 0;
};

template <int N>
class Fibonacci
{
    static constexpr FibonacciImpl<N> theImpl{};
};

int main()
{
    Fibonacci<10>{};
    return 0;
}