#include <iostream>
#include <Algoritmos.h>
#include <ctime>//Para las pruebas de tiempo
#include <fstream>

using namespace std;

int main()
{
    Algoritmos a;
    unsigned t0, t1;

    double time;
    ofstream texto("Datos_alg_6.txt");
    float aux=0;
    for(int i=0;i<20;i++){

        t0=clock();

        for(int i=0;i<1000000;i++)
            a.algoritmo6(8,2);


        t1=clock();

        time=(double(t1-t0)/CLOCKS_PER_SEC);
        cout << "Execution Time: " << time << endl;
        texto << time << "\n";
        aux+=time;
    }
    aux/=20;
    cout << aux;


    //cout << a.algoritmo2(412,260);
    //cout << a.algoritmo6(412,260);
    return 0;
}
