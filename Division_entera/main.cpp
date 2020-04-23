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
    if(b==0)return a;
    int r = fun_mod(a,b);
    fun_mcd(b,r);
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
  //  cout << fun_mcd(4864,3458) << endl;


    unsigned t0, t1;

    t0=clock();
    cout <<  fun_mod(260,152);
    for(int i=0;i<20000000;i++){
        fun_mod(260,152);//Aumenta en un 10-8% la velocidad sin la evaluacion de -a;
    }

    t1=clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    t0=clock();
    cout << 260-152*int(260/152);
    for(int i=0;i<200000000;i++){
        260-152*int(260/152);//Cream sin llamar a la funcion;
    }

    t1 = clock();

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    t0=clock();
    cout << 260%152;
    for(int i=0;i<200000000;i++){
        260%152;//Modulo directo
    }

    t1 = clock();

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;






    return 0;
}
