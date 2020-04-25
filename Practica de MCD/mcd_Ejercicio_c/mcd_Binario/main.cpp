#include <iostream>

using namespace std;
int mcd_Binario(int a,int b){
    int t,g;
    g=1;

    if(a<0)a=-a;
    if(b<0)b=-b;

    while(a%2==0&&b%2==0){
        cout << g << " " << a << " " << b << endl;
        a/=2;
        b/=2;
        g*=2;
    }
    while(a!=0){
        cout << g << " " << a << " " << b << endl;
        if(a%2==0)a/=2;
        else if(b%2==0)b/=2;
        else {
            if(a-b<0)t=(b-a)/2;
            else t=(a-b)/2;
            if(a>=b)a=t;
            else b=t;
        }
    }

    return g*b;

}
int main()
{

    cout << mcd_Binario(89,44) << endl;
    cout << mcd_Binario(8,48) << endl;
    return 0;
}
