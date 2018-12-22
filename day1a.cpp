#include <iostream>

int main()
{
    long s = 0;
    long v;
    while (std::cin>>v)
        s += v;
    std::cout << s << std::endl;
    return 0;
}
