#include <iostream>
#include <thread>

#include <cmath>

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

vector<int> mut::primesUpTo(int inclusiveMax)
{
    if(inclusiveMax <= 1)
    {
        cout << "mut::primesUpTo(int incluseiveMax) -> Invalid argument. inclusiveMax must be greater than 1." << endl;
        return vector<int>();
    }

    bool nums[inclusiveMax];

    for(int i = 0; i < inclusiveMax; i++)
    {
        nums[i] = true;
    }

    int max = sqrt(inclusiveMax);
    for(int i = 2; i <= max; i++)
    {
        if(nums[i])
        {
            for(int j = i * i; j <= inclusiveMax; j+=i)
            {
                nums[j] = false;
            }
        }
    }

    vector<int> output;
    for(int i = 2; i <= inclusiveMax; i++)
    {
        if(nums[i])
            output.push_back(i);
    }
    return output;
}

int main()
{
    mut m;
    //list<int> nums = { 25, 200, 500, 900, 250 };
    //cout << m.gcd(nums) << endl;

    vector<int> res = m.primesUpTo(1800);

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}