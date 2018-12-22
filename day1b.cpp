#include <iostream>
#include <map>
#include <vector>

int main()
{
    auto freqs = std::map<long,bool>{};
    auto deltas = std::vector<long>{};

    long v;
    while (std::cin>>v)
        deltas.push_back( v );

    long s = 0;

    for (;;)
        for (auto d:deltas)
        {
            // std::cout << d << " ";
            freqs[s] = true;
            s += d;
            if (freqs[s])
            {
                std::cout << s << std::endl;
                return 0;
            }
        }
    return 0;
}
