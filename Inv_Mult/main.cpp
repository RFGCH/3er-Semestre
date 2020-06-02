#include <iostream>
#include <ctime>
#include <NTL/ZZ.h>
#include <inv_mult.h>

using namespace std;
using namespace NTL;


int main()
{
    ZZ a;
    a=conv<ZZ>("23");
    ZZ b;
    b=conv<ZZ>("26");
    inv_mult setr(a,b);
    cout << setr.get_result();

    return 0;
}
