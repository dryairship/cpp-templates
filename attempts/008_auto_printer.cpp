template <auto Something>
class AutoPrinterImpl;

template <auto Something>
class AutoPrinter
{
    AutoPrinterImpl<Something> theImpl;
};

int main()
{
    AutoPrinter<3>{};
    AutoPrinter<4.55>{};
    AutoPrinter<-3030>{};
    AutoPrinter<'A'>{};
    AutoPrinter<true>{};
    return 0;
}