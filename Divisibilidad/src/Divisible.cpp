#include "Divisible.h"

Divisible::Divisible()
{}

bool Divisible::fun_Div(int a,int b){
    return (a/b==0) ? true:false;
}
bool Divisible::fun_Div2(int a,int b){
    int aux = a;
    while(true){
        if(a==b){
            return true;
        }
        else if(-a==b){
            return true;
        }
        if(a>b)
            return false;
        else if(-a>b)
                return false;
        a+=aux;
    }
}
