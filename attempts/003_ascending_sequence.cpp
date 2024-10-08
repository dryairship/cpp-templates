
template <int N>
class IntPrinter;

template <int N>
class AscendingSequence
{
    AscendingSequence<N-1> theSubSequence;
    IntPrinter<N> thePrinter;
};

template <>
class AscendingSequence<0>
{
};


int main()
{
    AscendingSequence<12>{};
    return 0;
}