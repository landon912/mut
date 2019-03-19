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

int mut::abs(int num)
{
    return num >= 0 ? num : -num;
}

unsigned int mut::abs(unsigned int num)
{
    return num >= 0 ? num : -num;
}

float mut::abs(float num)
{
    return num >= 0 ? num : -num;
}

float mut::lerp(float a, float b, float t)
{
    return a * (1-t) + (b * t);
}

bool mut::isPrime(int num)
{
    unsigned int nn = abs(num);
    return isPrime(nn);
}

bool mut::isPrime(unsigned int num)
{
    if(num == 1)
        return false;
    return num == 2 || num % 2 != 0;
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

    float t = 0.0f;
    while(t <= 1.05f)
    {
        cout << t << endl;
        cout << m.lerp(0,100,t) << endl;
        t+=0.1f;
    }
}