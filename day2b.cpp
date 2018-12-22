#include <iostream>

#include <string>
#include <vector>

#include <algorithm>

int diff( std::string &s1, std::string &s2 )
{
    auto i1 = std::begin(s1);
    auto i2 = std::begin(s2);

    int c = 0;

    do
    {
        auto p = std::mismatch( i1, std::end(s1), i2 );
        // std::cout << *i1 << *i2 << " " << std::fflush;
        if (p.first==std::end(s1))
            break;
        i1 = p.first+1;
        i2 = p.second+1;
        c++;
    }   while (true);

    // std::cout << "[" << s1 << "/" << s2 << "=" << c << "]" << std::endl;

    return c;
}

std::string common( std::string &s1, std::string &s2 )
{
    auto i = std::begin(s2);
    std::string s;

    for (auto c:s1)
    {
        if (c==*i)
            s += c;
        i++;
    }

    return s;
}

int main()
{
    std::vector<std::string> data;

    std::string s;
    while (std::cin>>s)
    {
        data.push_back( s );
    }

    for (auto i=std::begin(data);i!=std::end(data);i++)
        for (auto j=i+1;j!=std::end(data);j++)
            if (diff(*i,*j)==1)
                std::cout << common( *i,*j) << std::endl;
    return 0;
}
