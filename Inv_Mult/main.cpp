#include <iostream>
#include <ctime>
#include <NTL/ZZ.h>
#include <inv_mult.h>

using namespace std;
using namespace NTL;


int main()
{
    mat ma;
    ZZ a;
    a=conv<ZZ>("561");
    ZZ b;
    b=conv<ZZ>("634");
    cout << ma.inv_mult(a,b).at(2);

    return 0;
}
