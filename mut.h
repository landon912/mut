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
    int abs(int num);
    unsigned int abs(unsigned int num);

    //primes
    bool isPrime(int num);
    bool isPrime(unsigned int num);
    vector<int> primesUpTo(int inclusiveMax);
};

#endif