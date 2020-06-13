#include <iostream>
#include <Algoritmos.h>
#include <ctime>//Para las pruebas de tiempo
#include <fstream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

int main()
{
    Algoritmos a;
 /*
    unsigned t0, t1;

    double time;
    ofstream texto("Datos_alg_6.txt");
    float aux=0;
*/
    ZZ num1;
    num1 = conv<ZZ>("1491404400");
    ZZ num2;
    num2 = conv<ZZ>("1217312051");

/*
    for(int i=0;i<1;i++){

        t0=clock();
*/
         cout << a.algoritmo1(num1,num2);
/*
        t1=clock();

        time=(double(t1-t0)/CLOCKS_PER_SEC);
        cout << "Execution Time: " << time << endl;
        texto << time << "\n";
        aux+=time;
    }
    aux/=20;
    cout << aux;
*/

    //cout << a.algoritmo2(412,260);
    //cout << a.algoritmo6(412,260);
    return 0;
}
