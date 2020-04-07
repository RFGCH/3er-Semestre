#include <iostream>

using namespace std;
    int func(int x,int y,int z){
        x/= z;
        int a=x(x+y)/2;
        return a;
    }
int main()
{

    cout << func(1,100,1) << endl;
    return 0;
}
