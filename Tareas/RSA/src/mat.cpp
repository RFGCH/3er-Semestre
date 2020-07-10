#include "mat.h"
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

mat::mat()
{}
ZZ mat::resto_chino(ZZ a1,ZZ p1, ZZ a2, ZZ p2){
    a1=mod(a1,p1);
    a2=mod(a2,p2);
    ZZ P = p1*p2;
    ZZ q1 = inv_mult(mod(p2,P),p1);
    ZZ q2 = inv_mult(mod(p1,P),p2);
    return mod(mod(a1*p2*q1,P)+mod(a2*p1*q2,P),P);
}
ZZ mat::inv_mult(ZZ a,ZZ n){

    ZZ save=n;
    ZZ aux,r,q;
    ZZ inv1=conv<ZZ>("0");
    ZZ inv2=conv<ZZ>("1");

    do{
        q=n/a;
        r = n-a*q;
        n=a; a=r;
        aux = inv1-q*inv2;
        inv1=inv2;
        inv2=aux;
    }while(r!=0);

    if(inv1>0)
        return inv1;
    return save+inv1;
}
ZZ mat::mcd(ZZ m, ZZ n){
    ZZ r;
    do{
        r=mod(m,n);
        m=n;n=r;
    }while(r!=0);

    return m;
}
ZZ mat::pow_mod(ZZ base,ZZ potencia,ZZ n){
    ZZ aux = base;
    ZZ total = conv<ZZ>("1");
    while(potencia>0){
        if(potencia%2){
            total*=aux;
            total=mod(total,n);
        }
        aux*=aux;
        aux=mod(aux,n);
        potencia/=2;
    }
    total=mod(total,n);
    return total;
}
ZZ mat::pow(ZZ base,ZZ potencia){
    ZZ aux = base;
    ZZ total = conv<ZZ>("1");
    while(potencia>0){
        if(potencia%2){
            total*=aux;
        }
        aux*=aux;
        potencia/=2;
    }
    return total;
}
ZZ mat::mod(ZZ a,ZZ b){
    ZZ r = a-b*(a/b);
    if(r<0)return r+b;
    return r;
}
ZZ mat::Primo_n_Bits(ZZ bits){
    ZZ k =conv<ZZ>(200);  // Number of iterations
    srand(time(NULL));
    ZZ limite_inferior = pow(conv<ZZ>(2),bits)/2;
    ZZ limite_superior = pow(conv<ZZ>(2),bits)-1;
    ZZ n = limite_superior;
    n-=(n/(conv<ZZ>(rand())+2)); // Se le suma desde su mitad (con rand = 0) n seria solo 3/4 de limite_superior
    if(n%2==0)n+=1;
    while(Miller_Rabin(n,k)==0){
        n+=2;
        if(n>limite_superior)
            n-=limite_inferior;
    }
    cout << n << endl;
    return n;
}
bool mat::Miller_Test(ZZ d, ZZ n){
    ZZ a = conv<ZZ>(2+rand())%(n-4);
    ZZ x = pow_mod(a,d,n);

    if(x==1||x==n-1)
       return true;

    while(d!=n-1){
        x=(x*x)%n;
        d*=2;

        if(x==1)return false;
        if(x==n-1)return true;
    }
    return false;
}
bool mat::Miller_Rabin(ZZ n, ZZ k){
    if(n<=1||n==4)return false;
    if(n<=3)return true;

    ZZ d = n-1;
    while(d%2==0)d/= 2;

    for(int i=0;i<k;i++)
         if(!Miller_Test(d,n))
              return false;
    return true;

}

