template <int N>
class IntPrinter;

template <int N>
struct FactorialImpl
{
    static constexpr FactorialImpl<N-1> theSubFactorial{};
    static constexpr int theResult = N * theSubFactorial.theResult;
};

template <>
struct FactorialImpl<0>
{
    static constexpr int theResult = 1;
};

template <int N>
class Factorial
{
    static constexpr FactorialImpl<N> theImpl{};
    IntPrinter<theImpl.theResult> thePrinter;
};

int main()
{
    Factorial<6>{};
    return 0;
}