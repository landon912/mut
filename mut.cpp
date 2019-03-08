#include <iostream>
#include <thread>

#include "mut.h"

using namespace std;

int mut::min(int x, int y)
{
    return x > y ? y : x;
}

int mut::max(int x, int y)
{
    return x > y ? x : y;
}

int mut::gcd(int x, int y)
{
    if(x<y)
        return gcd(y,x);

    if(x%y == 0)
        return y;
    else
        return gcd(y, x%y);
}

int mut::gcd(list<int> vals)
{
    auto f = vals.begin();
    auto n = ++f;
    f--;
    do
    {
        *f = gcd(*f, *n);
        if(*f == 1)
            return 1;
        
        int temp = *n;
        n++;
        vals.remove(temp);
    }
    while(n != vals.end());

    return *f;
}

string mut::gcd_lc(int x, int y)
{   
    return "";
}

int main()
{
    mut m;
    list<int> nums = { 25, 200, 500, 900, 250 };
    cout << m.gcd(nums) << endl;
}