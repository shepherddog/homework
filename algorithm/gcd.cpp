#include <assert.h>
#include <iostream>
int gcd(int m,int n)
{
    int r;
    assert(m>0&&n>0);

    while((r=m%n)!=0)
    {
        m=n;
        n=r;
    }
    return n;
}

int main(int argc, char *argv[])
{
    std::cout << gcd(200,342) << std::endl;
    return 0;
}
