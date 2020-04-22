#include <iostream>
#include "math_tools.h"
#include "classes.h"
#include "tools.h"
#include "sel.h"
#include "display_tools.h"

using namespace std;

int main(void)
{
    vector<Matrix> localks;
    vector<Vector> localbs;

    Matrix K;
    Vector b;
    Vector T;

    cout << "IMPLEMENTACION DEL METODO DE LOS ELEMENTOS FINITOS" << endl;
    cout << "\t-TRANSFERENCIA DE CALOR EN 1D" << endl;
    cout << "\t-FUNCIONES DE FORMA LINEAL" << endl;
    cout << "\t-PESO DE GALERKIN" << endl;
    cout << "***********************************************************************" << endl;

    mesh m;
    leerMallayCondiciones(m);

    createLocalSystem(m, localks, localbs);

    zeroes(K, m.getSize(NODES));
    zeroes(b, m.getSize(NODES));
    assembly(m, localks, localbs, K, b);

    applyNeumann(m, b);
    applyDirichlet(m, K, b);
    zeroes(T, b.size());

    calculate(K, b, T);

    cout << "LA RESPUESTA ES: " << endl;

    showVector(T);

    return 0;
};