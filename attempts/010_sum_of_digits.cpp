#include <cstdint>

template <auto Something>
class AutoPrinter;

template <typename ResultContainer>
class PrintResult
{
    AutoPrinter<ResultContainer::theResult> thePrinter;
};

template <std::uint32_t N>
struct SumOfDigitsImpl
{
    static constexpr auto theResult = SumOfDigitsImpl<N / 10>::theResult + (N % 10);
};

template <std::uint32_t N>
requires (N < 10)
struct SumOfDigitsImpl<N>
{
    static constexpr auto theResult = N;
};

template <std::uint32_t N>
struct SumOfDigits
{
    static constexpr auto theResult = SumOfDigitsImpl<N>::theResult;
};

int main()
{
    PrintResult<SumOfDigits<2020>>{};
    PrintResult<SumOfDigits<123456>>{};
    PrintResult<SumOfDigits<3>>{};
    PrintResult<SumOfDigits<23478>>{};
    PrintResult<SumOfDigits<33333>>{};
    PrintResult<SumOfDigits<00000>>{};
    PrintResult<SumOfDigits<1110001>>{};
    return 0;
}