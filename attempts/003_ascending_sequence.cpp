#include <cstdint>

template <std::uint32_t N>
class UInt32Printer;

template <std::uint32_t N>
class AscendingSequence
{
    AscendingSequence<N-1> theSubSequence;
    UInt32Printer<N> thePrinter;
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