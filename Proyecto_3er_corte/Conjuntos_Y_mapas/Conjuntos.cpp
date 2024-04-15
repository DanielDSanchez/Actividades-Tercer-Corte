#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<string> frutas;

int main(int argc, char const *argv[])
{

    frutas.insert("arandanos");
    frutas.insert("uvas");
    frutas.insert("cerezas");
    frutas.insert("sandia");
    for (string fruta : frutas)
    {
        cout << fruta << endl;
    }

    return 0;

    set<string> canciones;
    canciones.insert("cancion1");
    canciones.insert("cancion2");
    canciones.insert("cancion3");
    canciones.insert("cancion4");
    canciones.erase("cancion2");
    canciones.erase("cancion1");

    auto it = canciones.find("cancion3");
    if (it != canciones.end())
    {
        cout << "Existe!" << endl;
    }

    set<int> a = {1, 2, 3, 4, 5, 6};
    set<int> b = {4, 5, 6, 7, 8, 9};

    set<int> cunion = a;
    cunion.insert(b.begin(), b.end());

    set<int> interseccion;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(interseccion, interseccion.begin()));

    set<int> diferencia;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(diferencia, diferencia.begin()));
}
