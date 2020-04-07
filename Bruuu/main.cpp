#include <iostream>
using namespace std;


void calendario(int a, int m){
 //Inicio del primer dia de ese mes y ese año

    //Definimos valores regulares

    int ini;
    int imes[]={0,3,3,6,1,4,6,2,5,0,3,5};//El inicio de cada mes
    int diasmes[]={31,28,31,30,31,30,31,31,30,31,30,31};

    //Actualizamos valores dependientes al año bisiesto

    if(a%4==0){
        for(int i=10;i!=0;i--)
            imes[1+i]+=1;
        diasmes[1]++;
    }

    //Si el usuario desea ingresar un año antes de cristo debe usar años negativos ej. 200a.c. -> -200

    if(a<=0){
        a%=-28;
        a+=28;
    }

    a--;
    a%=28;
    ini=a%7;
    a/=4;
    ini=(ini+a+imes[m-1])%7;

 //Imprimir la plantilla

    cout << " |  Domingo  | "
    << "  Lunes   | "
    << "  Martes  | "
    << "Miercoles | "
    << "  Jueves  | "
    << " Viernes  | "
    << "  Sabado  |" << endl;

    int dia = 1;
    int diares = diasmes[m-1];

    for(int i=6;i!=0;i--){
        cout << " |";
        for(int j=7;j!=0;j--){
            while(ini){
                cout << "           |"; ini-- ;j--;
            }
            if(diares && dia<10){
                cout << "     " << dia++ << "     |";
                diares--;
            }
            else if(diares && dia>=10){
                cout << "     " << dia++ << "    |";
                diares--;
            }
            else if(diares==0)cout << "           |";
        }
        cout << endl;
    }

    return;
}

int main(){
    int fecha;//La letra ñ produce errores, por lo que no se pudo usar año como variable
    int mes;
    cout<<"Ingrese la fecha: ";
    cin>>fecha;
    cout<<"Ingrese el mes: ";
    cin>>mes;
    calendario(x,mes);
    return 0;
}
