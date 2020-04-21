#include <iostream>

using namespace std;

class div_entera{
public:
    div_entera(int a,int b){
        int aux=b;
        int i=0;
        if(a>=0){
            for(;b<=a;b+=aux)
                i++;
            a-=(b-aux);
        }
        else{
            for(;b>=a;b-=aux)
                i--;
            i++;
            a-=b;
        }
        n=i;
        m=a;
    }
    int get_div(){
        return n;
    }
    int get_res(){
        return m;
    }
    int n;
    int m;
};


int main()
{
    int i;
    int j;
    div_entera a(264,5);
    i=a.get_div();
    j=a.get_res();
    cout << i << " " << j << endl;
    return 0;
}
