#include <iostream>
#include <sstream>

using namespace std;

string Rail_fence(string men,int c){

    int ini = 0;
    int tam = men.size();
    int aux = c*2-2;
    int aux2=0;
    string cod = "";
    while(c--){
        aux2 = (c+1)*2-2;
        int i = ini;
        while(i<tam){
            ostringstream aux_str;
            aux_str << men[i];
            cod.append(aux_str.str());
            if(aux2==0)aux2=aux;
            i+=aux2;
            aux2=aux-aux2;
        }
        ini++;
    }
    return cod;
}

int main()
{
    cout << Rail_fence("abcdefghij",5) << endl;
    return 0;
}
