#ifndef AHORCADO_H
#define AHORCADO_H
#include <string>

using namespace std;

class ahorcado
{
    public:
        ahorcado();
        virtual ~ahorcado();

    protected:

    private:

        int run;
        int intentos;
        string palabra_clave;
        string palabra;
        string palito;

        void init();
        void set_values();
        void print();
        void proceso_de_palabra();
        void comprobar();
        void fin_del_juego();
        void palito_str();
        void letra_str(string);
        void palabra_str(string);
        int numero_aleatorio();
        string getpalabra();
};

#endif // AHORCADO_H
