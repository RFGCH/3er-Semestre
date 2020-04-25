#include <iostream>
#include <math.h>

using namespace std;
int Min(int a,int b){
    return (a<b) ? a:b;
}
int pot(int a,int b){
    if(b==0) return 1;
    int i =0;
    for(i=0;i<=b;i++){
        a*=b;
    }
    cout << i<< endl;
    return a;
}
int LSBGCD(long a,long b){
    long r,aux,s;
    int con=1;
    cout << "\n\LSBGCD 1:\n" << endl;
    cout << "	 a     b     r     s\n" << endl;
    cout << "Paso 1  " << a <<"   " << b << "    -" << "    -" << endl;
    if(a<0)a=-a;
    if(b<0)b=-b;
    cout << "Paso 2  " << a <<"   " << b << "    -" << "    -" << "   if(a<0)a=-a; if(b<0)b=-b;" << endl;
    while (b!=0){
        s=0;
        cout << "\n        ---Vuelta "<<con<<"----" << endl;
        con++;
        for(;b*pow(2,s)<=a;s++);
        s--;
        cout << "Paso 3  " << a <<"   " << b << "    " << r << "   " << s << "  while(b*2^s<=a){s++;}s--;" << endl;

        r=Min(a-b*pow(2,s),b*pow(2,s+1)-a);
        a = b;
        b = r;
        cout << "Paso 4  " << a <<"   " << b << "    " << r << "   " << s << "  r=min(a-b*2^s,(b*2^s+1)-a)" << endl;


        if(a<b){
            aux = a;
            a = b;
            b = aux;
        cout << "Paso 5  " << a <<"   " << b << "    " << r << "   " << s << "  if(a<b)switch(a,b);   " << "True;" << endl;
        }
        else    cout << "Paso 5  " << a <<"   " << b << "    " << r << "   " << s << "  if(a<b)switch(a,b);   "<< "False;"<< endl;
    }
        return a;
}

int main()
{

    cout << LSBGCD(55367,28731);
    return 0;
}
