#include "mat.h"
#include <iostream>
using namespace std;
mat::mat()
{}
int mat::resto_chino(int a1,int p1, int a2, int p2){
    a1=mod(a1,p1);
    a2=mod(a2,p2);
    int P = p1*p2;
    int q1 = inv_mult(mod(p2,P),p1);
    int q2 = inv_mult(mod(p1,P),p2);
    return mod(mod(a1*p2*q1,P)+mod(a2*p1*q2,P),P);
}
int mat::inv_mult(int a,int n){

    int save=n;
    int aux,r,q;
    int inv1=0;
    int inv2=1;

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
int mat::mcd(int m, int n){
    int r;
    do{
        r=mod(m,n);
        m=n;n=r;
    }while(r!=0);

    return m;
}
int mat::pow(int base,int potencia,int n){
    base=mod(base,n);
    potencia=mod(potencia,n);
    int aux = base;
    int total = 1;

    while(potencia>0){
        if(potencia%2){
            total*=aux;
            total=mod(total,n);
        cout <<total << " " << aux << endl;
        }
        aux*=aux;
        aux = mod(aux,n);
        potencia/=2;
    }
    return total;
}
int mat::mod(int a,int b){
    int r = a-b*(a/b);
    if(r<0)return r+b;
    return r;
}
