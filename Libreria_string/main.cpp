#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <time.h>
#include "ahorcado.h"

using namespace std;

void rot13(string &a){
        for(int i=0;i<a.size();i++)
        if(a[i]>109&&a[i]<123||a[i]>77&&a[i]<91)//Lee minuscula y mayuscula
            a[i]=char(a[i]-13);//si esta en el limite retrocede envez de adelantar
        else if(a[i]>96&&a[i]<110||a[i]>64&&a[i]<78)
            a[i]=char(a[i]+13);//se asigna el valor en 13 posiciones adelante
}
void decodificar(string &a,int clave){
        for(int i=0;i<a.size();i++)
        if(a[i]>122-clave&&a[i]<123||a[i]>90-clave&&a[i]<91)//La misma dinamica que el encriptador, pero haciendo uso de una llave
            a[i]=char(a[i]-clave);//dependiendo de la clave este valor se ajustara
        else if(a[i]>96&&a[i]<97+clave||a[i]>64&&a[i]<65+clave)
            a[i]=char(a[i]+clave);
}
int main()
{

    ///Ejercicios del capitulo

    /// 18.7: Algoritmo rot13

    // a)Encriptar un mensaje mediante el algoritmo rot13
/*
    string cadena1;//inicialisamos la cadena
    cout << "Valor a codificar: ";
    getline(cin,cadena1);//se le asigna el valor
    rot13(cadena1);//Recurrimos a una funcion
    cout << "Valor codificado: ";
    cout << cadena1 << endl;//imprimimos el resultado
*/

    //b)

    //Previamente se codifico el mensaje en el
    //ejercicio a, por lo tanto se usara para decodificar
/*
    decodificar(cadena1,13);//a diferencia del codificador, este necesita usar una clave
    cout << "Descodificacion del mismo mensaje: ";
    cout << cadena1 << endl;//imprime el resultado
*/
    //c)
/*
    el problema a mi parecer con esto es saber cuando el mensaje
    ya esta descodificado pues puede que para un humano un
    mesaje tenga sentido tras ser descodificado pero para la
    maquina seria igual al codificado sin dicha informacion
*/
    /// 18.11: Suma de nombre y apellido
/*
    string nombre1;
    string apellido1;
    cout << "Ingrese su nombre: ";
    getline(cin,nombre1);
    cout << "Ingrese su apellido: ";
    getline(cin,apellido1);
    string id=nombre1+" "+apellido1;//se hace uso de suma de string(tambien es valido con .append)
    cout << "Su nombre es: ";
    cout << id <<endl;;
*/
    ///18.12: El ahorcado
/*
    ahorcado a;
*/
    ///18.19: Mitad de un string
/*
    string cadena2;
    cout << "Ingrese una cadena: ";
    getline(cin,cadena2);
    cadena2.insert(cadena2.size()/2,"******");
    cout << "Cadena modificada: ";
    cout << cadena2<< endl;
*/
    ///18.21: Reemplazo y strtok
/*
    string cadena3;//cadena inicial
    cout << "Ingrese la frase a cambiar: ";
    getline(cin,cadena3);//asigna el valor a la cadena
    int pos = cadena3.find_first_of(".,;:[]?¿()-!¡<>");//inicia con la primera posicion encontrada
    while(pos!=string::npos){
        cadena3.replace( pos, 1, " " );//remplaza la posicion por un " "
        pos = cadena3.find_first_of( ".,;:[]?¿()-!¡<>", pos + 1 );//busca apartir de la posicion siguiente
    }
    cout << "Tras la conversion: ";
    cout << cadena3 << endl;
    cout << "Tokens:"<< endl;
    //Uso de la funcion strtok

    char* aux = new char[cadena3.size()];//se crea un array para contener el string
    char delim[]=" ";//se inicia el delimitador
    for(int i=0;i<cadena3.size();i++)
        aux[i]=cadena3[i];//se le azignan los valores a el contenedor
    char* token = strtok(aux,delim);//uso de la funcion strtok
    while (token)
    {
        cout << token << endl;//Cuando se ingresa un valor sin signos de puntuacion
        token = strtok(NULL,delim);//este falla, tira basura junto a la palabra
    }
*/
    ///18.22: Ecribir la inversa
/*
    string cadena4;
    cout << "Ingrese una cadena: ";
    getline(cin,cadena4);
    cout << "Impreso con iteradores alrevez: ";
    string::const_iterator iterador1= cadena4.end();//comenzamos por el final
    while(iterador1!=cadena4.begin()){//terminamos con el inicio
        iterador1--;//se retrocede(se puede hacer con const_reverse_iterator)
        cout << *iterador1;
    }
    cout << endl;
*/
    ///18.27: Ordenamiento por seleccion
/*
    string cadena5;
    cout << "Ingresar una cadena para ordenar: ";
    getline(cin,cadena5);
    cout << "La cadena ordenada es: ";
    for(int i=0;i<cadena5.size();i++)
        for(int j=1+i;j<cadena5.size();j++){
            if(cadena5[i]>cadena5[j])
                swap(cadena5[i],cadena5[j]);
        }
    cout <<cadena5<< endl;
*/
    ///Práctica: Clase String
    ///1.- De string a array char y viceversa:
/*
    string cadenax;
    cout << "Ingresar una cadena(sin espacios): ";//Da errores cuando se ingresa un espacio " "
    getline(cin,cadenax);
    char* aux1= new char [cadenax.size()];

    istringstream cadenaaux1(cadenax);
    cadenaaux1 >> aux1 ;
    cout << "Este es un array tipo char: ";
    for(int i=0;i<cadenax.size();i++)
        cout << aux1[i];
    cout << endl;
    cout << "Este es un string: ";
    ostringstream cadenaaux2;
    cadenaaux2 << aux1;
    string a = cadenaaux2.str();
    cout << a;
*/
    ///2.- Diferencia entre capacity y size:
/*
    La función capacity retorna el valor de capacidad de
    la string mientras la funcion size nos retorna la
    cantidad de valores en la string
*/
    ///3.- De minuscula a mayuscula y viceversa:
/*
    string cadena6;
    cout << "Ingrese una cadena: ";
    getline(cin,cadena6);
    cout << "Invirtiendo mayusculas y minusculas sale: ";
    for(int i=0;i<cadena6.size();i++)
        if(cadena6[i]>96&&cadena6[i]<123)
            cadena6[i]-=32;
        else if(cadena6[i]>64&&cadena6[i]<91)
            cadena6[i]+=32;
    cout << cadena6 << endl;
*/
    ///4.- De enteros a string y su doble:
/*
    int int1;
    cout << "Ingrese el primer numero: ";
    cin >> int1;
    int int2;
    cout << "Ingrese el segundo numero: ";
    cin >> int2;

    ostringstream cadenaSalida;
    cadenaSalida << int1 << int2;

    string cadena7;
    cadena7+=cadenaSalida.str();

    istringstream cadenaEntrada(cadena7);
    int int3;
    cadenaEntrada >> int3 ;

    cout << "Unidos es: ";
    cout << int3 << endl;
    cout << "Y su doble es: ";
    int3*=2;
    cout << int3 << endl;
*/
    ///5.- String de 1000 veces a:
/*
    cout << "\"Se a creado una cadena de 1000 veces a\""<< endl;
    string cadena(1000,'a');
*/
    ///6.- De "desaprobe" a "aprobe":
/*
    string cadena8 = "Yo desaprobe el curso de Algebra Abstracta";
    cout << cadena8 << endl;
    string cadena9 = "";
    int pos1 = cadena8.find("des");
    cadena8.replace(pos1,3,cadena9);
    cout << "Tras encontrar el error: ";
    cout << cadena8 << endl;
*/
    ///7.-  Apariciones de una palabra en un string:
/*
    string cadena10;
    string cadena11;
    cout <<"Ingrese una frase: ";
    getline(cin,cadena10);
    cout << "Ingrese la palabra a buscar: ";
    getline(cin,cadena11);

    int cant=0;
    int pos2 = cadena10.find(cadena11);
    for(;pos2 != string::npos;cant++)//seria más usual el uso de while, esto es una experimentacion
        pos2 = cadena10.find(cadena11,pos2+1);
    cout << "Cantidad de veces encontrado: ";
    cout << cant << endl;
*/
    ///8.- Cout con iteradores:
/*
    string cadena12;
    getline(cin,cadena12);
    string::const_iterator iterador2= cadena12.begin();
    while(iterador2!=cadena12.end())
        cout << *iterador2++;
*/
    ///9.- Segundo en medio del primero:
/*
    string cadena13;
    cout << "Ingrese su primera cadena: ";
    getline(cin,cadena13);
    string cadena14;
    cout << "Ingrese su segunda cadena: ";
    getline(cin,cadena14);
    int pos3 = cadena13.size()/2;
    cadena13.insert(pos3,cadena14);
    cout << "La segunda en medio de la primera: ";
    cout << cadena13<< endl;
*/
    ///10.- Reemplazo por consola:
/*
    string cadena15;
    cout <<"Ingrese la frase: ";
    getline(cin,cadena15);
    string cadena16;
    cout << "Ingrese la palabra a buscar: ";
    getline(cin,cadena16);
    string cadena17;
    cout << "Ingrese la palabra con la que reemplazar: ";
    getline(cin,cadena17);

    int pos4 = cadena15.find(cadena16);

    while(pos4!=string::npos){
        cadena15.replace( pos4,cadena16.size(), cadena17 );
        pos4 = cadena15.find( cadena16, pos4 + cadena16.size());
    }
    cout <<"La cadena modificada: ";
    cout << cadena15<< endl;
*/
    ///11.- La palabra lexicograficamente mayor:
/*
    string cadena18;
    cout << "Ingresar la primera palabra: ";
    getline(cin,cadena18);
    string cadena19;
    cout << "Ingresar la segunda palabra: ";
    getline(cin,cadena19);
    cout << "La cadena lexicograficamente mayor es: ";
    if (cadena18<cadena19)
        cout << cadena18 << endl;
    else
    cout << cadena19 << endl;
*/
    ///12.- N numeros de un archivo:
/*
    int int4;
    cout << "Ingrese la cantidad de numeros(entre 1 a 10): ";
    cin >> int4;
    cout << "Los primeros " << int4 << " numeros del archivo numeros.txt:" << endl;
    ifstream leer;
    leer.open("numeros.txt");
    string cadena20;
    while(int4--){
        getline(leer,cadena20);
        cout << cadena20 << endl;
    }
    leer.close();
*/
    ///13.- Sumatoria de los numeros en el archivo:
/*
    int int5=0;
    int aux2=0;
    ifstream leer1;
    leer1.open("numeros.txt");
    string cadena21;
    cout << "Los numeros en numeros.txt son:"<< endl;
    while(!leer1.eof()){
        getline(leer1,cadena21);
        cout << cadena21 << endl;
        istringstream cdEntrada(cadena21);
        cdEntrada >> aux2;
        int5+=aux2;
    }
    cout << "Y su sumatoria es: ";
    cout << int5<< endl;
    leer1.close();
    */
    return 0;
}
