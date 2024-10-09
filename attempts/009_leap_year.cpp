#include <cstdint>

template <auto Something>
class AutoPrinter;

template <typename ResultContainer>
class PrintResult
{
    AutoPrinter<ResultContainer::theResult> thePrinter;
};

template <std::uint32_t Dividend, std::uint32_t Divisor>
class IsDivisibleBy
{
    static constexpr bool theResult = Dividend % Divisor == 0;
};

template <std::uint32_t Year>
class IsLeapYear
{
    static constexpr bool theResult = IsDivisibleBy<Year, 4>::theResult
                                        && !IsDivisibleBy<Year, 100>::theResult
                                        || IsDivisibleBy<Year, 400>::theResult;
};

int main()
{
    PrintResult<IsLeapYear<2020>>{};
    PrintResult<IsLeapYear<2000>>{};
    PrintResult<IsLeapYear<2021>>{};
    PrintResult<IsLeapYear<2100>>{};
    PrintResult<IsLeapYear<2200>>{};
    PrintResult<IsLeapYear<2400>>{};
    PrintResult<IsLeapYear<1999>>{};
    return 0;
}