#include "Algoritmos.h"
#include <iostream>
#include <math.h>

using namespace std;
Algoritmos::Algoritmos()
{}

int Algoritmos::algoritmo1(int a,int b){
    int r;
    //int con=1;
    //cout << "\n\tAlgoritmo 1:\n" << endl;
    //cout << "	 a     b     r\n" << endl;
    //cout << "Paso 1  " << a <<"   " << b << "    -"<< endl;
    do{
        //cout << "\n        ---Vuelta "<<con<<"----" << endl;
        r=fun_mod(a,b);
        //cout << "Paso 2  " << a << "   " << b << "   " << r << endl;
        //cout << "Paso 3  " << a << "   " << b << "   " << r << endl;
        if(r==0){
            //cout << "True;"<< endl;
            return b;
        }
        //cout << "False;" << endl;
        a=b;b=r;
        //cout << "Paso 4  " << a << "   " << b << "   " << r << endl;
        //con++;
    }while(r!=0);
}
int Algoritmos::algoritmo2(int a,int b){
    int r;
    int con=1;
    //cout << "\n\tAlgoritmo 2:\n" << endl;
    //cout << "	 a     b     r\n" << endl;
    //cout << "Paso 1  " << a <<"   " << b << "    -"<< endl;
    do{
        //cout << "\n        ---Vuelta "<<con<<"----" << endl;
        r=fun_mod(a,b);
        //cout << "Paso 2  " << a << "   " << b << "   " << r << endl;
        //cout << "Paso 3  "<<a<<"   "<<b<<"   "<<r<<"    r="<<r<<";";
        if(r==0){
            //cout << "True;"<< endl;
            return b;
        }
        //cout << "False;" << endl;
        //cout << "Paso 4  " << a << "   " << b << "   " << r <<"    r>="<<b/2<<";";
        if(r>b/2){
            r=b-r;
            //cout << "True;"<< endl;
        }
        else; //cout << "False;" << endl;
        a=b;b=r;
        //cout << "Paso 5  " << a << "   " << b << "   " << r << endl;
        con++;
    }while(r!=0);
}
int Algoritmos::algoritmo3(int a, int b){
    //cout << "Paso 1: "<<a<<"   "<<b<< "   si b es 0 return a;"<< endl;
    if(b==0)return a;
    //cout << "Paso 2: "<<a<<"   "<<b<< "   si b distinto de 0 return algoritmo3(b,fun_mod(a,b));"<< endl;
    return algoritmo3(b,fun_mod(a,b));
}
int Algoritmos::algoritmo3_5(int a,int b){
    int aux;
    cout << "\n\tAlgoritmo 3_5:\n" << endl;
    cout << "	 a     b   \n" << endl;
    cout << "Paso 1:  " << a <<"   " << b<< endl;
    while(b!=0){
        a=fun_mod(a,b);
        cout <<"Paso 2:  "<< a << "   " << b << " a = fun_mod(a,b)"<<  endl;
        aux=a;
        a=b;
        b=aux;
        //cout<< "Paso3:   "<< a << "   "<< b << "  switch(a,b); "<< endl;
    }
    return a;
}
int Algoritmos::algoritmo4(int a,int b){
    if(fun_abs(b)>fun_abs(a)){
        //cout << "Paso 1:  " << a <<"   " << b<<"   si |a|<|b|, switch(a,b);"<< endl;
		return algoritmo4(b,a);
	}
	if(b==0){
            //cout << "Paso 1:  " << a <<"   " << b<<"   si b es 0, return a;"<< endl;
            return a;
	}
	if(a%2==0&&b%2==0){
            //cout << "Paso 2:  " << a <<"   " << b<<"   mientras a y b son par, algoritmo4(a/2,b/2);"<< endl;
            return 2*algoritmo4(a/2,b/2);
	}
	else if(a%2==0&&b%2!=0){
            //cout << "Paso 3:  " << a <<"   " << b<<"   mientras a es par, algoritmo4(a/2,b);"<< endl;
            return algoritmo4(a/2,b);
	}
	else if(a%2!=0&&b%2==0){
        //cout << "Paso 3:  " << a <<"   " << b<<"   mientras b es par, algoritmo4(a,b/2);"<< endl;
        return algoritmo4(a,b/2);
	}
	else {
        //cout << "Paso 3:  " << a <<"   " << b<<"   si no, algoritmo4(|a-b|/2,b);"<< endl;
        return algoritmo4(fun_abs(a-b)/2,b);
	}

}
int Algoritmos::algoritmo5(int a,int b){
    int t;
    int g=1;
    cout << "\n\tAlgoritmo 3_5:\n" << endl;
    cout << "	 a     b   r\n" << endl;
    while(fun_mod(a,2)==0&&fun_mod(b,2)==0){
        a/=2;
        b/=2;
        g=2*g;
    cout << "Paso 1:  " << a <<"   " << b << "    - " << g << "   mientras a y b sean pares g^2" << endl;
    }
    while(a!=0){
        while(fun_mod(a,2)==0){
            cout << "Paso 2:  " << a <<"   " << b << "    -"<< "   mientras a par, a/=2;" << endl;
            a/=2;
        }
        while(fun_mod(b,2)==0){
            cout << "Paso 3:  " << a <<"   " << b << "    -"<< "   mientras b par, a/=2;" << endl;
            b/=2;
        }
        t=fun_abs(a-b)/2;
        cout << "Paso 4:  " << a <<"   " << b << "   "<< t << "   t = |a,b|/2;" << endl;
        if(a>=b)a=t;
        else b=t;
        cout << "Paso 5:  " << a <<"   " << b << "   "<< t << "   mientras b par, a/=2;" << endl;
    }
    return g*b;
}
int Algoritmos::algoritmo6(int a,int b){
    cout << "\n\tAlgoritmo 3_5:\n" << endl;
    cout << "	 a     b   \n" << endl;
    cout << "Paso 1:  " << a <<"   " << b << "   mientras a y b sean diferentes:" << endl;
    while(a!=b)
        if(a>b) {
            cout << "Paso 2:  " << a <<"   " << b << "   si a>b, a-=b;" << endl;
            a-=b;
        }
        else {
            cout << "Paso 2:  " << a <<"   " << b << "   si no, b-=a;" << endl;
            b-=a;
        }
    return a;
}
int Algoritmos::fun_mod(int a, int b){
    a=fun_abs(a);
    b=fun_abs(b);
    int r = a-b*(a/b);//Si no fuera division entera, usaria  floor(a/b+0.5);
    if(b-r<r)return b-r;
    return r;
}
int Algoritmos::fun_abs(int a){
 return (a<0) ? -a:a;
}
