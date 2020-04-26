#include <iostream>

using namespace std;
bool fun_Div(int a,int b){
    return (a/b==0) ? true:false;
}
bool fun_Div2(int a,int b){
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
int main()
{

    cout << fun_Div(-3,12);

    return 0;
}
