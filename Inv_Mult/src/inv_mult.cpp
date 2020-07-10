#include "inv_mult.h"

mat::mat()
{
}

vector<ZZ> mat::inv_mult(ZZ a,ZZ n){

    ZZ save=n;
    ZZ aux2,aux,r,q;
    ZZ inv1=conv<ZZ>("0");
    ZZ inv2=conv<ZZ>("1");
    ZZ t1 = conv<ZZ>("1");
    ZZ t2 = conv<ZZ>("0");
    ZZ condicion = mcd(a,n);
    vector<ZZ> ret;
    if(condicion==conv<ZZ>("1")){
    do{
        q=n/a;
        r = n-a*q;
        n=a; a=r;

        aux = inv1-q*inv2;
        inv1=inv2;inv2=aux;

        aux2 = t1-q*t2;
        t1=t2;t2=aux2;
    }while(r!=0);

    ret.push_back(conv<ZZ>("-1"));
    ret.push_back(conv<ZZ>("-1"));
    ret.push_back(conv<ZZ>("-1"));
    }
    else return ret;

    ret.clear();

    ret.push_back(condicion);
    ret.push_back(inv1);
    ret.push_back(t1);

    if(inv1>0)
        return ret;
    ret.at(1)+=save;
    return ret;
}
ZZ mat::mcd(ZZ m, ZZ n){
    ZZ r;
    do{
        r=mod(m,n);
        m=n;n=r;
    }while(r!=0);

    return m;
}
ZZ mat::mod(ZZ a,ZZ b){
    ZZ r = a-b*(a/b);
    if(r<0)return r+b;
    return r;
}

