#include "RSA.h"

RSA::RSA(ZZ bits)
{

    alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
    generarclave(bits);

}
void RSA::generarclave(ZZ bits)
{
    //escojemos de manera aleatoria 2 primos

    p = fun.Primo_n_Bits(bits);
    q = fun.Primo_n_Bits(bits);
    while(p==q)q = fun.Primo_n_Bits(bits);

    //calculamos las variables n y fi de n

    n=p*q;
    ZZ fi_n=(p-1)*(q-1);

    //clave publica

    publica=fun.mod(fun.Primo_n_Bits(bits),n);
    while(publica==q||publica==q)publica=fun.mod(fun.Primo_n_Bits(bits),n);
    while(fun.mcd(publica,fi_n)!=1)
        publica=fun.mod(fun.Primo_n_Bits(bits),n);

    //clave privada

    privada=fun.inv_mult(publica,fi_n);

    //cout << p <<endl;
    //cout << q << endl;
    //cout << n << endl;
    //cout << fi_n<<endl;
    //cout << publica << endl;
    //cout <<privada << endl;

}
string RSA::cifrar(string mensaje,ZZ clave,ZZ n){
    ZZ tam_n = tam(n);
    ZZ tam_alf = tam(conv<ZZ>(alfabeto.size()));
    string total,total2;

    //Posición en alfabeto y se guardan los bloques de posiciones en total
    for(int i=0;i<mensaje.size();i++){
        ZZ pos = conv<ZZ>(alfabeto.find(mensaje[i]));
        total+=cifrar_str(pos,tam_alf);
    }
    ZZ tam_total = conv<ZZ>(total.size());
    //Agregar basura al final del string de ser necesario
    for(ZZ i=fun.mod(tam_total,tam_n-1);i<tam_n-1;i++)
        total.insert(total.size(),"0");

    while(total.size()>conv<ZZ>("0")){

    //Extraemos el bloque de tamaño n
    string str_aux = total.substr(0,conv<int>(tam_n)-1);
    total.erase(0,conv<int>(tam_n)-1);
    //Lo pasamos a ZZ para hacer la potencia
    istringstream istr_aux(str_aux);
    ZZ in;
    istr_aux >> in;
    in=fun.pow_mod(in,publica,n);
    //Agregamos los 0 a cada bloque de ser necesario y se guarda
    str_aux=cifrar_str(in,tam_n);
    total2+=str_aux;
    }
    return total2;

}
string RSA::descifrar(string mensaje){

    ZZ tam_n = tam(n);
    ZZ tam_total = conv<ZZ>(mensaje.size());
    ZZ tam_alf = tam(conv<ZZ>(alfabeto.size()));

    string contenedor1,contenedor2,str_aux;

    while(tam_total>0){

        //Separamos por subconjuntos de tamaño n

        str_aux = mensaje.substr(0,conv<int>(tam_n));
        mensaje.erase(0,conv<int>(tam_n));

        //Lo pasamos a ZZ para hacer la potencia

        istringstream istr_aux(str_aux);
        ZZ zz_aux;
        istr_aux >> zz_aux;
        zz_aux=pow_desc(zz_aux);

        //Lo pasamos a string para guardarlo

        str_aux = cifrar_str(zz_aux,tam_n-1);
        contenedor1+=str_aux;
        tam_total=tam_total-tam_n;

    }

    //Extraemos los bloques de tamaño tam_alf
    tam_total = conv<ZZ>(contenedor1.size());
    for(int i=0;i<tam_total;i+=conv<int>(tam_alf)){
        int pos = descifrar_str(contenedor1,i);
        contenedor2 += alfabeto[pos];
    }

    return contenedor2;
}
ZZ RSA::tam(ZZ a){
    if(a==conv<ZZ>("0"))return conv<ZZ>("1");//si es 0 tiene una cifra
    ZZ cont = conv<ZZ>("0");
    while(a!=conv<ZZ>("0")){a/=10;cont++;}
    return cont;
}
string RSA::cifrar_str(ZZ numero,ZZ tam_p){

    // Agregar 0 si el numero lo necesita

    tam_p=tam_p-tam(numero);
    string cadena(conv<int>(tam_p),'0');

    // Agregar el valor del numero a la cadena

    ostringstream aux;
    aux << numero;
    cadena.append(aux.str());

    return cadena;
}
int RSA::descifrar_str(string mensaje,int tam_n){

    // Desde tam_n escoje tam_alf numeros para pasarlos a un entero

    int tam_alf = conv<int>(tam(conv<ZZ>(alfabeto.size())));
    string str_aux = mensaje.substr(tam_n,tam_alf);

    // Se pasa a entero la cadena substraida

    istringstream igstr_aux(str_aux);
    int pos;
    igstr_aux >> pos;

    return pos;
}
ZZ RSA::pow_desc(ZZ c){

    ZZ expo_p=fun.mod(privada,p-1);
    ZZ expo_q=fun.mod(privada,q-1);

    return fun.resto_chino(fun.pow_mod(c,expo_p,p),p,fun.pow_mod(c,expo_q,q),q);

}
