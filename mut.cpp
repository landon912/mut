#include <iostream>
#include <thread>

#include <cmath>

#include "mut.h"

using namespace std;
namespace mut
{
int mut::min(int x, int y)
{
    return x > y ? y : x;
}

int mut::max(int x, int y)
{
    return x > y ? x : y;
}

float mut::toRad(float degrees)
{
    return degrees * (3.14159265358979323846 / 180.0f);
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

int mut::abs(int n)
{
    return n >= 0 ? n : -n;
}

unsigned int mut::abs(unsigned int n)
{
    return n >= 0 ? n : -n;
}

float mut::abs(float n)
{
    return n >= 0 ? n : -n;
}

float mut::lerp(float a, float b, float t)
{
    return a * (1-t) + (b * t);
}

bool mut::isPrime(int n)
{
    unsigned int nn = abs(n);
    return isPrime(nn);
}

bool mut::isPrime(unsigned int n)
{
    if(n == 1)
        return false;
    return n == 2 || n % 2 != 0;
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

bool mut::divides(int d, int n)
{
    if(d == 0)
        return false;
    return n%d == 0;
}

bool mut::propDivides(int d, int n)
{
    if(d == 0)
        return false;
    return n%d == 0 && n != d;
}

int mut::sigmaFunc(int n)
{
    return sigmaFunc(n, 1);
}

int mut::sigmaFunc(int n, int p)
{
    int sum = 0;
    for(int i = 0; i <= n; i++)
    {
        if(divides(i,n))
        {
            sum += pow(i, p);
        }
    }
    return sum;
}

int mut::aliquotSum(int n)
{
    return sigmaFunc(n)-n;
}

#include <climits>

unsigned long long int mut::factorial(int n)
{
    unsigned long long int r = 1ULL;
    for(int i = 2; i <= n; i++)
    {
        r = r * i;
        cout << "Range left: " << ULLONG_MAX - r << endl;
    }
    return r;
}

unsigned long long int mut::stirlingApprox(unsigned long long int n)
{
    //this is a modified version of sterling's approximation of factorials
    //from: Weisstein, Eric W. "Stirling's Approximation." From MathWorld--A Wolfram Web Resource. http://mathworld.wolfram.com/StirlingsApproximation.html 
    return sqrt((2*(long double)n+(1.0/3.0))*M_PI) * pow((long double)n,n) * pow((long double)M_E, -n);
}
}

int main()
{
    mut::mut m;
    clock_t startTime = clock();
    double secondsPassed = 0;

    cout << m.factorial(21) << endl;
    cout << m.stirlingApprox(21) << endl;

    for(int i = 0; i < 100000000; i++)
    {
        float n = i%142;

        //m.factorial(n);
        //m.stirlingApprox(n);
    }

    secondsPassed = (clock() - startTime) / CLOCKS_PER_SEC;

    //cout << secondsPassed << endl;
}