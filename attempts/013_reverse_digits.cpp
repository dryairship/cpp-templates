#include <cstdint>

template <auto Something>
class AutoPrinter;

template <typename ResultContainer>
class PrintResult
{
    AutoPrinter<ResultContainer::theResult> thePrinter;
};

template <std::uint32_t DigitsYetToReverse, std::uint32_t PartiallyReversedDigits>
struct ReverseDigitsImpl
{
    static constexpr auto theNewDigitsYetToReverse = DigitsYetToReverse / 10;
    static constexpr auto theNewPartiallyReversedDigits = 
            PartiallyReversedDigits * 10 + DigitsYetToReverse % 10;

    static constexpr auto theResult = ReverseDigitsImpl<
            theNewDigitsYetToReverse, theNewPartiallyReversedDigits>::theResult;
};

template <std::uint32_t PartiallyReversedDigits>
struct ReverseDigitsImpl<0, PartiallyReversedDigits>
{
    static constexpr auto theResult = PartiallyReversedDigits;
};

template <std::uint32_t N>
struct ReverseDigits
{
    static constexpr auto theResult = ReverseDigitsImpl<N, 0>::theResult;
};

int main()
{
    PrintResult<ReverseDigits<12345678>>{};
    PrintResult<ReverseDigits<12321>>{};
    PrintResult<ReverseDigits<1002003>>{};
    PrintResult<ReverseDigits<5>>{};

    PrintResult<ReverseDigits<100>>{}; // Doesn't really work, prints 1 instead of 001
    return 0;
}