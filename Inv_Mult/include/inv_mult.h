#ifndef INV_MULT_H
#define INV_MULT_H
#include <NTL/ZZ.h>
#include <vector>

using namespace NTL;
using namespace std;

class mat
{
    public:

        mat();
        vector<ZZ>inv_mult(ZZ,ZZ);
        ZZ mcd(ZZ,ZZ);
        ZZ mod(ZZ,ZZ);

};

#endif // INV_MULT_H
