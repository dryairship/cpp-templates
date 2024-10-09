#include <cstdint>

template <auto Something>
class AutoPrinter;

template <typename ResultContainer>
class PrintResult
{
    AutoPrinter<ResultContainer::theResult> thePrinter;
};

template <std::uint32_t NumberToCheck, std::uint32_t PotentialDivisor>
struct IsPrimeImpl
{
    static constexpr auto theResult = (NumberToCheck % PotentialDivisor != 0)
                        && IsPrimeImpl<NumberToCheck, PotentialDivisor - 1>::theResult;
};

template <std::uint32_t NumberToCheck>
struct IsPrimeImpl<NumberToCheck, 1>
{
    static constexpr auto theResult = true;
};

template <std::uint32_t NumberToCheck>
requires (NumberToCheck <= 1)
struct IsPrimeImpl<NumberToCheck, 0>
{
    static constexpr auto theResult = false;
};


template <std::uint32_t NumberToCheck>
struct IsPrime
{
    static constexpr auto theResult = IsPrimeImpl<NumberToCheck, NumberToCheck / 2>::theResult;
};

int main()
{
    PrintResult<IsPrime<0>>{};
    PrintResult<IsPrime<1>>{};
    PrintResult<IsPrime<2>>{};
    PrintResult<IsPrime<3>>{};
    PrintResult<IsPrime<4>>{};
    PrintResult<IsPrime<5>>{};
    PrintResult<IsPrime<6>>{};
    PrintResult<IsPrime<7>>{};
    PrintResult<IsPrime<8>>{};
    PrintResult<IsPrime<9>>{};
    PrintResult<IsPrime<10>>{};
    PrintResult<IsPrime<11>>{};
    PrintResult<IsPrime<12>>{};
    PrintResult<IsPrime<13>>{};
    return 0;
}