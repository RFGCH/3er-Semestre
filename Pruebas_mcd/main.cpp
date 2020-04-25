#include <iostream>
#include <ctime>

using namespace std;

class div_entera{
public:
    div_entera(int a,int b){
        int aux=b;
        n=0;
        if(a>=0){
            for(;b<=a;b+=aux)
                n++;
            m=a-(b-aux);
        }
        else{
            for(;b>=a;b-=aux)
                n--;
            n++;
            m=a-b;
        }
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

int fun_mod(int a,int b){

    int i=0;
    if(a<0){a=-a;i=1;}//Se elimina la excepcion en b <=0; dado que no entra dento de la definicion de modulo
    int aux=b;
    for(;b<=a;b+=aux);//Esto debo mejorar
    if(i)return b-a;
    return a-b+aux;
}
int cquo(int a,int b){
    if(b==0)return a;
    int q = int(a/b);
    if(b<0)q=q+1;
    return q;
}
int crem(int a,int b){
    return a-b*cquo(a,b);
}
int fun_mcd(int a, int b){
    int r;
    while(b!=0){
        r=fun_mod(a,b);
        a=b;
        b=r;
    }
    return a;
}
int fun_mod2(int a, int b){
    return a%b;
}
bool fun_divisivilidad(int a, int b){
    if(fun_mod(b,a)==0)
        return true;
    return false;
}

int main()
{

    int i;
    int j;
    div_entera a(264,5);
    i=a.get_div();
    j=a.get_res();
    cout << i << " " << j << endl;
    cout << fun_mcd(77,7)<<endl;
  //  cout << fun_mcd(4864,3458) << endl;

    unsigned t0, t1;

    t0=clock();
    cout <<  fun_mod(260,10);
    for(int i=0;i<2000000;i++){
        fun_mod(26123456789,11234567);//Aumenta en un 10-8% la velocidad sin la evaluacion de -a;y evalueando a b aumenta un 20%;
    }//Solo es mejor cuando a >= b*26;si se distancian más, deja de ser mejor, con respecto a crem, el cual sin funcion es similar a el modulo.(sin evaluar en b)

    t1=clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    t0=clock();
    cout << crem(260,10);
    for(int i=0;i<20000000;i++){
        crem(26123456789,11234567);//Cream sin llamar a la funcion;
    }
    260-10*int(260/10);
    t1 = clock();

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    t0=clock();
    cout << 260%10;
    for(int i=0;i<20000000;i++){
        26123456789%11234567;//Modulo directo
    }

    t1 = clock();

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;






    return 0;
}
