template <int N>
class IntPrinter;

template <int... Ns>
class VariadicSum
{
    static constexpr int theSum = (Ns + ...);
    IntPrinter<theSum> thePrinter;
};

int main()
{
    VariadicSum<1, 4>{};
    VariadicSum<23, 7, 9>{};
    VariadicSum<1, 2, 3, 4, 5, 6, 7, 8, 9, 10>{};
    return 0;
}