
template <int N>
class IntPrinter;

template <int A, int B>
class Multiplier
{
    IntPrinter<A*B> thePrinter;
};


int main()
{
    Multiplier<12,25>{};
    return 0;
}