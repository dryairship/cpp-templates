
template <int N>
class IntPrinter;

template <int A, int B>
class Adder
{
    IntPrinter<A+B> thePrinter;
};


int main()
{
    Adder<56,2> myAdder;
    return 0;
}