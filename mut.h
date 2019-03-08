#ifndef MUT_H
#define MUT_H

#include <string>
#include <list>

using std::string;
using std::list;

class mut
{
public:
    int min(int x, int y);
    int max(int x, int y);
    int gcd(int x, int y);
    int gcd(list<int> vals);
    string gcd_lc(int x, int y); //finds linear combination of gcd
};

#endif