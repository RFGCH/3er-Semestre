#include <iostream>
#include <RSA.h>
#include <mat.h>

using namespace std;

int main()
{
    RSA Juan(conv<ZZ>(64));
    string cifrado = Juan.cifrar("Esto deberia poder cifrarse, pero imaginate cifrar un parrafo de wikipedia xd, veamos... Diocleciano (nombre completo, Cayo Aurelio Valerio Diocleciano Augusto, en latin Gaius Aurelius Valerius Diocletianus Augustus) (c. 24 de diciembre de 244-3 de diciembre de 311), nacido con el nombre de Diocles, fue emperador de Roma desde el 20 de noviembre de 284 hasta el 1 de mayo de 305. Nacido en una familia iliria de bajo estatus social, fue escalando puestos en la jerarquia militar hasta convertirse en el comandante de la caballeria del emperador Caro. Tras la muerte de Caro y de su hijo Numeriano en campana en Persia, Diocleciano fue aclamado emperador por el ejercito. Consiguio acceder al trono tras un breve enfrentamiento con Carino, el otro hijo del emperador Caro, en la batalla del Margus, y su llegada al poder puso fin a la crisis del siglo iii.Diocleciano nombro a Maximiano coemperador, otorgandole el titulo de Augusto de occidente en 285. El 1 de marzo de 293 nombro a Galerio y a Constancio como cesares, un titulo similar al de principe o heredero del augusto. Este nuevo regimen, conocido como la tetrarquia, o ",Juan.publica,Juan.n);
    cout << Juan.descifrar(cifrado);
    return 0;
}
