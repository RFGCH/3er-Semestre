#include <iostream>
#include <math.h>
using namespace std;

int Menor_entero(int a,int b){
    float r,c,d;
    if(a==0)a=b;
    int con=0;
    cout << "\n\Menor resto 1:\n" << endl;
    cout << "	 a     b     r\n" << endl;
    cout << "Paso 1  " << a <<"   " << b << "    -"<< endl;
    while(b!=0){
        con++;
        cout << "\n        ---Vuelta "<<con<<"----" << endl;
        r=a-b*floor(a/b+0.5);
        cout << "Paso 2  " << a << "   " << b << "   " << r << endl;
        a=b;
        b=r;
        cout << "Paso 3  " << a << "   " << b << "   " << r << endl;
    }
    return (a<0)? -a:a ;
}

int main()
{
    cout << Menor_entero(-144,-89);
    return 0;
}
