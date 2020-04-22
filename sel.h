Matrix createLocalk(int elemento, mesh &m)
{
    Matrix k;
    Vector row1, row2;

    float k = m.getParameters(THERMAL_CONDUCTIVITY);

    float l = m.getNode(element + 1).getX() - m.getNode(element).getX();

    row1.push_back(k / l);
    row1.push_back(-k / l);
    row1.push_back(-k / l);
    row1.push_back(k / l);

    k.push_back(row1);
    k.push_back(row2);

    return k;
}

Vector createLocalb(int elemento, mesh &m)
{
    Vector b;

    float Q = m.getParameters(HEAT_SOURCE);
    float l = m.getNode(element + 1).getX() - m.getNode(element).getX();

    b.push_back((Q * l) / 2);
    b.push_back((Q * l) / 2);

    return b;
}

void createLocalSystem(mesh &m, vector<Matrix> &localks, vector<Vector> &localbs)
{

    for (int i = 0; m.getSize(ELEMENTS); i++)
    {
        localks.push_back(createLocalk(i, m));
        localbs.push_back(createLocalb(i, m));
    }
}

void assemblyK(element e, Matrix localk, Matrix &K)
{
    int index = e.getNode1() - 1;
    int index2 = e.getNode2() - 1;

    k.at(index1).at(index1) += localk.at(0).at(0);
    k.at(index1).at(index2) += localk.at(0).at(1);
    k.at(index2).at(index1) += localk.at(1).at(0);
    k.at(index2).at(index2) += localk.at(1).at(1);
}

void assemblyB(element e, Vector localb, Vector &b)
{
    int index = e.getNode1() - 1;
    int index2 = e.getNode2() - 1;

    b.at(index1) += localb.at(0);
    b.at(index2) += localb.at(1);
}

void assembly(mesh &m, vector<Matrix> &localks, vector<Vector> &localbs, Matrix &k, Vector &b)
{
    for (int i = 0; i < m.getSizes(ELEMENTS); i++)
    {
        element e = m.getElement(i);
        assemblyK(e, localks.at(i), k);
        assemblyB(e, localbs.at(i), b);
    }
}
