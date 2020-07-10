#include "Primos.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

Primos::Primos()
{
    int siz = 10;

    //crear lista grande
    ostringstream o;
    for(int i=2;i<=siz;i++)
        o<<i<<".";
    string a = o.str();

    //leer int
    string a1,a2;
    int pos,cont,n1,n2;

    for(int i=0;i<a.size();i++)
        if(a[i]!='.')
            a1+=a[i];
        else{
            //pasamos a int
            n1=0;
            istringstream aux(a1);
            aux >> n1;
            //buscamos entre los siguientes y borramos
            for(int j=i+1;j<a.size();j++)
                if(a[j]!='.'){
                    a2+=a[j];
                    cont++;
                }
                else if(cont!=0){
                    //pasamos a int
                    n2=0;
                    istringstream aux2(a2);
                    aux2 >> n2;
                    //borramos si es multiplo
                    if(n2%n1==0){
                            pos = a.find(a2);
                            a.erase(pos,cont+1);
                    }
                    //reestablecemos valores
                    a2 = "";
                    cont = 0;
                }
            //reestablecemos valores
            a1 = "";
        }
//
    //pos = n;
    int posicion=2;
    int numero=23;

    int contador =0;
    while(posicion){
        if(a[contador]=='.'){
            posicion--;
        }
        contador++;
    }
    posicion=contador;
    while(a[contador++]!='.');

    ostringstream ostr_aux;
    ostr_aux<<numero;
    string n=ostr_aux.str();
    a.erase(posicion,contador-posicion-1);
    a.insert(posicion,n);
//
    // n = c[pos]
    cout << a << endl;
    ofstream texto("Primeros_10000000_Primos.txt");
    texto<<a;
}
