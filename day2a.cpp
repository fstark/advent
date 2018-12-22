#include <iostream>

#include <string>
#include <map>

void count( std::string &s, bool &d, bool &t )
{
    auto cnt = std::map<char,int>{};
    auto set2 = std::map<char,int>{};

    for (auto c:s)
    {
        cnt[c]++;
    }

    d = t = false;

    for (auto i:cnt)
    {
        if (i.second==2)
            d = true;
        if (i.second==3)
            t = true;
    }
}

int main()
{
    std::string s;

    long dcount = 0;
    long tcount = 0;

    while (std::cin>>s)
    {
        bool d,t;

        count( s, d, t );
        dcount += d;
        tcount += t;
    }

    std::cout << dcount*tcount << std::endl;
    return 0;
}
