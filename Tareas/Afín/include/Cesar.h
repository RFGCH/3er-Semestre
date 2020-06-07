#ifndef CESAR_H
#define CESAR_H
#include <string>

using namespace std;
class Cesar
{
    public:
        Cesar();
        string cifrado(string,int);
        string descifrar(string,int);
        int mod(int,int);

        string alfabeto;

};

#endif // CESAR_H
