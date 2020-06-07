#include "mat.h"

mat::mat()
{}
int mat::mcd(int m, int n){
    int r;
    do{
        r=mod(m,n);
        m=n;n=r;
    }while(r!=0);

    return m;
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
int mat::mod(int a,int b){
    int r = a-b*(a/b);
    if(r<0)return r+b;
    return r;
}
