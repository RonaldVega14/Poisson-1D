#include <fstream>
#include <iostream>
#include "classes.h"

using namespace std;

int main(void)
{
    vector<Matrix> localks;
    vector<Vector> localbs;

    Matrix k;
    Vector b;
    Vector t;

    cout << "IMPLEMENTACION DEL METODO DE LOS ELEMENTOS FINITOS" << endl;
    cout << "\t-TRANSFERENCIA DE CALOR EN 1D" << endl;
    cout << "\t-FUNCIONES DE FORMA LINEAL" << endl;
    cout << "\t-PESO DE GALERKIN" << endl;
    cout << "***********************************************************************" << endl;

    mesh m;
    leerMallayCondiciones(m);

    createLocalSystem(m, localks, localbs)

        zeroes(k, m.getSize(NODES));
    zeroes(b, m.getSize(NODES));

    return 0;
};