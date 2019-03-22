#ifndef MUT_H
#define MUT_H

#include <string>
#include <list>
#include <vector>

using std::string;
using std::list;
using std::vector;

class mut
{
public:
    int min(int x, int y);
    int max(int x, int y);
    
    //gcd
    int gcd(int x, int y);
    int gcd(list<int> vals);
    string gcd_lc(int x, int y); //finds linear combination of gcd

    //abs
    int abs(int n);
    unsigned int abs(unsigned int n);
    float abs(float n);

    //interpolations
    float lerp(float a, float b, float t);

    //primes
    bool isPrime(int n);
    bool isPrime(unsigned int n);
    vector<int> primesUpTo(int inclusiveMax);

    //number theoretic
    bool divides(int d, int n);
    bool propDivides(int d, int n);
    int sigmaFunc(int n);
    int sigmaFunc(int n, int p);
    int aliquotSum(int n);
    double stirlingApprox(double n);
};

#endif