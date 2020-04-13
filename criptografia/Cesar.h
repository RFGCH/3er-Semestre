#ifndef CESAR_H
#define CESAR_H
#include <iostream>

using namespace std;

class Cesar
{
public:

    Cesar();

    string cifrado(string);
    string descifrar(string);

    string alfabeto;

private:

    int clave;

};

#endif // CESAR_H
