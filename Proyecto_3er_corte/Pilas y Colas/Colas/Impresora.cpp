#include <iostream>
#include <string>
#include <queue>
#include <limits>
using namespace std;

class Impresora
{
private:
    queue<string> impresiones;

public:
    Impresora();
    void agregarImpresion(string impresion);
    void imprimir();
    void mostrarImpresiones();
};

Impresora::Impresora()
{
}

void Impresora::agregarImpresion(string impresion)
{
    impresiones.push(impresion);
    cout << "------------- Documento agregado a la cola ---------" << endl;
}

void Impresora::imprimir()
{
    cout << "--------- Imprimiendo... --------" << endl;
    if (!impresiones.empty())
    {
        cout << "Documento impreso: " << impresiones.front() << endl;
        impresiones.pop();
    }
    else
    {
        cout << "No hay impresiones" << endl;
    }
    cout << "---------------------------------" << endl;
}

void Impresora::mostrarImpresiones()
{
    queue<string> temp = impresiones;
    cout << "------------ Impresiones faltantes ------------" << endl;
    while (!temp.empty())
    {
        cout << "Documento: " << temp.front() << endl;
        temp.pop();
        cout << "----------------------------------------------" << endl;
    }
}

int main(int argc, char const *argv[])
{
    Impresora impresora;
    int opcion = 0;
    string impresion;

    do
    {
        cout << "1. Agregar impresion" << endl;
        cout << "2. Imprimir" << endl;
        cout << "3. Mostrar impresiones Faltantes" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion)
        {
        case 1:
        {
            cout << "Ingrese el documento a imprimir: ";
            getline(cin, impresion);
            impresora.agregarImpresion(impresion);
            break;
        }
        case 2:
            impresora.imprimir();
            break;
        case 3:
            impresora.mostrarImpresiones();
            break;
        default:
            break;
        }
    } while (opcion != 0);

    return 0;
}
