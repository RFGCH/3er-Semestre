#include <iostream>
#include <Vigenere_c.h>
#include <Kasiski_c.h>
using namespace std;

int main()
{

    Vigenere_c a;
    string aux="TRANQUILO SENTADO PIENSAS EN EL MIEDO QUE TE PRODUCE EL PENSAR EN TI MISMO, SINTIENDO COMO CADA ACCION QUE REALIZES TE ACERCA CADA VEZ MAS AL FRACASO, TRISTE Y TEMBLANDO TE ENFRENTAS A LA VIDA, PUES EL MIEDO NO PUEDE SUPERAR TUS VERDADERAS Y REALES INTENCIONES";
    //Kasiski_c c(aux);
    cout << aux<< endl;
    aux = a.cifrado(aux);
    cout << aux<< endl;
    Kasiski_c d(aux);
    return 0;
}
