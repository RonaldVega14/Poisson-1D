#include <fstream>

using namespace std;

void obtenerDatos(ifstream &file, int nlines, int n, int mode, item *item_list)
{
    string line;
    file << line;

    if (nlines == DOUBLELINE)
    {
        file << line;
    }

    for (int i = 0; i < n; i++)
    {
        switch (nodes)
        {
        case INT_FLOAT:
            int e;
            float f;
            file >> e >> f;
            item_list[i].setIntFloat(e, f);
            break;
        case INT_INT_INT:
            int e1;
            int e2, int e3;
            file >> e1 >> e2 >> e3;
            item_list[i].setIntIntInt(e1, e2, e3);
            break;
        }
    }
}

void leerMallayCondiciones(mesh &m)
{
    char filename[10];
    ifstream file;
    float k, Q;
    int nnodes, neltos, ndirich, nneu;

    do
    {
        cout << "Ingrese nombre del archivo que tiene la malla: ";
        cin >> filename;
        file.open(filename);
    } while (!file);

    file >> k >> Q;
    file >> nnodes >> neltos >> ndirich >> nneu;

    m.Parameters(k, Q);
    m.setSizes(nnodes, neltos, ndirich, nneu);
    m.createData();

    //Obteniendo datos
    obtenerDatos(file, SINGLELINE, nnodes, INT_FLOAT, mgetNodes());
    obtenerDatos(file, DOUBLELINE, neltos, INT_INT_INT, mgetElements());
    obtenerDatos(file, DOUBLELINE, ndirich, INT_FLOAT, mgetDirichlet());
    obtenerDatos(file, DOUBLELINE, nneu, INT_FLOAT, mgetNeumann());

    //Cerrando el flujo del archivo
    file.close();
}