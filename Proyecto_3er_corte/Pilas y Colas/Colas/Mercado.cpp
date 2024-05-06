#include <iostream>
#include <string>
#include <queue>
#include <limits>

using namespace std;

class Mercado
{
private:
    queue<string> listaCompras;

public:
    Mercado();
    void agregarCompra(string compra);
    void mostrarCompras();
    void eliminarCompra();
};

Mercado::Mercado()
{
}

void Mercado::agregarCompra(string compra)
{
    listaCompras.push(compra);
    cout << "------------- Compra agregada a la lista ---------" << endl;
}

void Mercado::mostrarCompras()
{
    cout << "------------ Compras pendientes ------------" << endl;
    if (listaCompras.empty())
    {
        cout << "La lista de compras esta vacia " << endl;
        cout << "----------------------------------------------" << endl;
    }
    else
    {
        queue<string> temp = listaCompras;
        while (!temp.empty())
        {
            cout << "Compra: " << temp.front() << endl;
            temp.pop();
            cout << "----------------------------------------------" << endl;
        }
    }
}

void Mercado::eliminarCompra()
{
    cout << "--------- Eliminando... --------" << endl;
    if (!listaCompras.empty())
    {
        cout << "Compra eliminada: " << listaCompras.front() << endl;
        listaCompras.pop();
    }
    else
    {
        cout << "No hay compras" << endl;
    }
    cout << "---------------------------------" << endl;
}

int main(int argc, char const *argv[])
{

    Mercado mercado;
    int opcion = 0;
    string compra;

    do
    {
        cout << "1. Agregar compra" << endl;
        cout << "2. Mostrar compras" << endl;
        cout << "3. Eliminar compra" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion)
        {
        case 1:
        {
            cout << "Ingrese la compra a la lista: ";
            getline(cin, compra);
            mercado.agregarCompra(compra);
            break;
        }
        case 2:
        {
            mercado.mostrarCompras();
            break;
        }
        case 3:
        {
            mercado.eliminarCompra();
            break;
        }
        default:
            opcion = 0;
            break;
        }

    } while (opcion != 0);
    return 0;
}
