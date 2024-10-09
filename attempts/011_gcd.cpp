#include <cstdint>

template <auto Something>
class AutoPrinter;

template <typename ResultContainer>
class PrintResult
{
    AutoPrinter<ResultContainer::theResult> thePrinter;
};

template <std::uint32_t A, std::uint32_t B>
struct GCDImpl
{
    static constexpr auto theResult = GCDImpl<B, A%B>::theResult;
};

template <std::uint32_t A, std::uint32_t B>
requires (A < B)
struct GCDImpl<A, B>
{
    static constexpr auto theResult = GCDImpl<B, A>::theResult;
};

template <std::uint32_t A>
struct GCDImpl<A, 0>
{
    static constexpr auto theResult = A;
};

template <std::uint32_t A, std::uint32_t B>
struct GCD
{
    static constexpr auto theResult = GCDImpl<A, B>::theResult;
};

int main()
{
    PrintResult<GCD<23, 5>>{};
    PrintResult<GCD<32, 64>>{};
    PrintResult<GCD<20, 90>>{};
    PrintResult<GCD<123, 69>>{};
    PrintResult<GCD<69, 123>>{};
    return 0;
}