
template <int N>
class IntPrinter;

template <int N>
class DescendingSequence
{
    IntPrinter<N> thePrinter;
    DescendingSequence<N-1> theSubSequence;
};

template <>
class DescendingSequence<0>
{
};


int main()
{
    DescendingSequence<12>{};
    return 0;
}