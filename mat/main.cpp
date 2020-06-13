#include <iostream>
#include <mat.h>
using namespace std;

int main()
{
    mat a;
    int a1 = a.resto_chino(2,9,3,7);
    int a2 = a.resto_chino(a1,9*7,1,4);
    int a3 = a.resto_chino(a2,9*7*4,-1,5);
    cout <<a3<< endl;
    return 0;
}
