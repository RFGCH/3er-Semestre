#include "mat.h"
#include <iostream>
using namespace std;

mat::mat()
{}
ZZ mat::resto_chino(ZZ a1,ZZ p1, ZZ a2, ZZ p2){
    a1=mod(a1,p1);
    a2=mod(a2,p2);
    ZZ P = p1*p2;
    ZZ q1 = inv_mult(mod(p2,P),p1);
    ZZ q2 = inv_mult(mod(p1,P),p2);
    return mod(mod(a1*p2*q1,P)+mod(a2*p1*q2,P),P);
}
ZZ mat::inv_mult(ZZ a,ZZ n){

    ZZ save=n;
    ZZ aux,r,q;
    ZZ inv1=conv<ZZ>("0");
    ZZ inv2=conv<ZZ>("1");

    do{
        q=n/a;
        r = n-a*q;
        n=a; a=r;
        aux = inv1-q*inv2;
        inv1=inv2;
        inv2=aux;
    }while(r!=0);

    if(inv1>0)
        return inv1;
    return save+inv1;
}
ZZ mat::mcd(ZZ m, ZZ n){
    ZZ r;
    do{
        r=mod(m,n);
        m=n;n=r;
    }while(r!=0);

    return m;
}
ZZ mat::pow_mod(ZZ base,ZZ potencia,ZZ n){
    ZZ aux = base;
    ZZ total = conv<ZZ>("1");
    while(potencia>0){
        if(potencia%2){
            total*=aux;
            total=mod(total,n);
        }
        aux*=aux;
        aux=mod(aux,n);
        potencia/=2;
    }
    total=mod(total,n);
    return total;
}
ZZ mat::pow(ZZ base,ZZ potencia){
    ZZ aux = base;
    ZZ total = conv<ZZ>("1");
    while(potencia>0){
        if(potencia%2){
            total*=aux;
        }
        aux*=aux;
        potencia/=2;
    }
    return total;
}
ZZ mat::mod(ZZ a,ZZ b){
    ZZ r = a-b*(a/b);
    if(r<0)return r+b;
    return r;
}
ZZ mat::Primo_n_Bits(ZZ bits){
    ZZ k =conv<ZZ>(200);  // Number of iterations
    ZZ limite_superior = pow(conv<ZZ>(2),bits)-1;
    ZZ n = Random(conv<int>(bits));
    if(n%2==0)n+=1;
    for(int i=0;Miller_Rabin(n,k)==0;i++){
        n+=2;
        if(n>limite_superior)
            n/=2+Random(4);
    }
    return n;
}
bool mat::Miller_Test(ZZ d, ZZ n){
    ZZ a = conv<ZZ>(2+Random(64)%(n-4));
    ZZ x = pow_mod(a,d,n);

    if(x==1||x==n-1)
       return true;

    while(d!=n-1){
        x=(x*x)%n;
        d*=2;

        if(x==1)return false;
        if(x==n-1)return true;
    }
    return false;
}
bool mat::Miller_Rabin(ZZ n, ZZ k){
    if(n<=1||n==4)return false;
    if(n<=3)return true;

    ZZ d = n-1;
    while(d%2==0)d/= 2;

    for(int i=0;i<k;i++)
         if(!Miller_Test(d,n))
              return false;
    return true;

}
ZZ mat::Random(int bits){
    int* Vec=DES_Test(RC4(),bits);
    ZZ total=conv<ZZ>(1);
    ZZ aux=conv<ZZ>(1);
    for(int i=0;i<bits;i++){
       if(Vec[i]){
            total+=aux;
       }
       aux*=2;
    }
    if(total<aux/2)total+=aux/2;
    return total;
}
int* mat::DES_Test(int* Vec64,int bits)
{
    //Inicializamos las tablas de 56 y 48. Junto a la tabla de desplazamiento

    int bits_Tabla_1=56;
    int bits_Tabla_2=48;

    int Tabla_PC_1_56bits[bits_Tabla_1]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    int Tabla_PC_2_48bits[bits_Tabla_2]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
    int Tabla_desplazamientos[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

    //Creamos el vector de 56 bits con la semilla

    int Vec56[bits_Tabla_1];
    for(int i=0;i<bits_Tabla_1;i++)
        Vec56[i]=Vec64[Tabla_PC_1_56bits[i]-1];

    // Separamos en 2 el vector de 56 bits

    int Vec28_1[28],Vec28_2[28];
    for(int i=0;i<bits_Tabla_1/2;i++){Vec28_1[i]=Vec56[i];}
    for(int i=bits_Tabla_1/2,j=0;i<bits_Tabla_1;i++,j++){Vec28_2[j]=Vec56[i];}

    // Llenamos el vector final con las permutaciones con la tabla 2

    int* Vec=new int[bits];
    for(int j=0,k=0;j<bits;j+=48,k++){

        //Creamos un aux que nos servira para reemplazar con el vector de 48 bits

//Desplazamiento a la izquierda
        int aux_Vec56[bits_Tabla_1];
        for(int i=0;i<28;i++)
            aux_Vec56[i]=Vec28_1[(i+Tabla_desplazamientos[k%16])%28];
        for(int i=0;i<28;i++)Vec28_1[i]=aux_Vec56[i];
//Desplazamiento a la derecha
        for(int i=28;i<56;i++)
            aux_Vec56[i]=Vec28_2[(i-Tabla_desplazamientos[k%16])%28];
        for(int i=28;i<56;i++)Vec28_2[i-28]=aux_Vec56[i];

        //Creamos y asignamos valores a el vector de 48 bits

        int Vec48[bits_Tabla_2];
        for(int i=0;i<bits_Tabla_2;i++)
            Vec48[i]=aux_Vec56[Tabla_PC_2_48bits[i]-1];

        //Llenamos el vector final con el de 48, hasta que se llenen los bits

        for(int i=0;i<48&&i+j<bits;i++){
            Vec[i+j]=Vec48[i];
        }
    }
    return Vec;
}
int* mat::RC4(){

    int bitsS=256;
    int bitsK=40;

//Generación de S

    int* S=new int[bitsS];
    for(int i=0;i<bitsS;i++)S[i]=i;

//Generación de semilla

    int semilla[5]={getheat()+gettime2(),gettime()};
    semilla[2]=(semilla[0]*semilla[1])%256;
    semilla[3]=(semilla[0]+semilla[1])%256;
    semilla[4]=(semilla[2]+semilla[3])%256;

//Generación de K

    int K[bitsK];
    int save;
    for(int i=0,j=0;i<bitsK;i++){
        if(i%8==0)save=semilla[j++];
        K[i]=save%2;
        save/=2;
    }

//Permutaciones de S

    int f=0;
    for(int i=0;i<bitsS;i++){
        f=(f+S[i]+K[i%bitsK])%bitsS;
        swap(S[i],S[f]);
    }
    return Secuencia_cifrante(S);
}
int* mat::Secuencia_cifrante(int* S){

    int bits = 64;
    int i,f,t,save;
    i=f=0;

    int *K=new int[bits];

    for(int k=0;k<bits/8;k++){

        i=(i+1)%256;
        f=(f+S[i])%256;
        swap(S[i],S[f]);
        t=(S[i]+S[f])%256;

        save=S[t];

        for(int j=0;j<8;j++){
            K[j+k*8]=save%2;
            save/=2;
        }
    }

    return K;
}

int mat::getheat(){
    HANDLE a = GetProcessHeap();
    return int(a)/65536;//Son los bits que siempre estan en 0 (16)
}
int mat::gettime(){
    SYSTEMTIME t;
    GetSystemTime(&t);
    return int(t.wMilliseconds)%256;
}
int mat::gettime2(){
    SYSTEMTIME t;
    GetSystemTime(&t);
    return int(t.wSecond)%256;
}
