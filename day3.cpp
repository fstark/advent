#include <iostream>

#include <string>
#include <vector>
#include <cassert>

struct claim
{
    int x,y,w,h;
};


const int max_size = 1001;
int fabric[max_size][max_size];

int paint( int area[max_size][max_size], claim &c )
{
    int duplicates = 0;
    for (auto y=c.y;y!=c.y+c.h;y++)
        for (auto x=c.x;x!=c.x+c.w;x++)
        {
            if (area[x][y]==1)
                duplicates++;
            area[x][y]++;
        }
    return duplicates;
}

int main()
{
    std::vector<claim> data;

       // '#1 @ 906,735: 28x17'
    int ignored,x,y,w,h;
    while (scanf( "#%d @ %d,%d: %dx%d\n", &ignored, &x, &y, &w, &h)==5)
    {
        data.push_back( {x,y,w,h} );
        assert( x>=0 );
        assert( y>=0 );
        assert( x+w<max_size );
        assert( y+h<max_size );
    }

    long s = 0;
    for (auto &c:data)
    {
        s += paint( fabric, c );
    }

    std::cout << "#1 : " << s << std::endl;

    int i = 0;
    for (auto &c:data)
    {
        auto res = paint( fabric, c );

        i++;
        if (res==c.w*c.h)
            std::cout << "#2 : " << i << std::endl;
    }

    return 0;
}
