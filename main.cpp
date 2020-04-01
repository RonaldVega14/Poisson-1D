// #include <iostream>
// #include "math_tools.h"
// #include "display_tools.h"
// using namespace std;
// int main(void){
//     Matrix matrix_example, matrix_inversa;

//     zeroes(matrix_example, 3);

//     matrix_example.at(0).at(0) = 2; matrix_example.at(0).at(1) = 2; matrix_example.at(0).at(2) = 3;
//     matrix_example.at(1).at(0) = 4; matrix_example.at(1).at(1) = 5; matrix_example.at(1).at(2) = 6;
//     matrix_example.at(2).at(0) = 7; matrix_example.at(2).at(1) = 8; matrix_example.at(2).at(2) = 9;

//     cout << "\nMatriz Original" << endl;

//     showMatrix(matrix_example);

//     inverse(matrix_example, matrix_inversa);

//     cout << "\nMatriz Inversa" << endl;

//     showMatrix(matrix_inversa);

//     return 0;

// }
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <fstream>
#include <iostream>
#include "classes.h"

using namespace std;

void readCoordinates(ifstream &file, int n, item *item_list)
{
    int e;
    float r;
    for (int i = 0; i < n; i++)
    {
        file >> e >> r;
        item_list[i].setIntFloat(e, r);
    }
};

void showNodesCoordenates(int n, item *item_list)
{
    cout << "Node"
         << "\t"
         << "X"
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << item_list[i].getId() << "\t" << item_list[i].getX() << "\n";
    }
}

int main(void)
{
    string filename;
    string line;
    mesh m;
    ifstream file;
    float k, Q;
    int nnodes, neltos, ndirich, nneu;

    do
    {
        cout << "Ingrese el nombre del archivo: ";
        cin >> filename;
        cout << "Abriendo: " << filename << "\n";
        file.open(filename);
    } while (!file);

    file >> k >> Q;
    file >> nnodes >> neltos >> ndirich >> nneu;

    file >> line;

    m.setParameters(k, Q);
    m.setSizes(nnodes, neltos, ndirich, nneu);
    m.createData();

    readCoordinates(file, nnodes, m.getNodes());

    file.close();

    showNodesCoordenates(nnodes, m.getNodes());

    return 0;
};
