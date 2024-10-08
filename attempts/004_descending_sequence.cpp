#include <cstdint>

template <std::uint32_t N>
class UInt32Printer;

template <int N>
class DescendingSequence
{
    UInt32Printer<N> thePrinter;
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