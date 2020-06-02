#include "inv_mult.h"

inv_mult::inv_mult(ZZ a, ZZ n)
{
    this -> a = a;
    this -> n = n;
}

ZZ inv_mult::get_result(){

    ZZ save=n;
    ZZ aux,r,q;
    ZZ inv1;
    inv1=0;
    ZZ inv2;
    inv2=1;

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
