#include <iostream>
#include <stack>
#include <string>
#include <limits>
using namespace std;

class Llamada
{
private:
    string numero;
    string fecha;

public:
    Llamada(string numero);
    string getNumero() const;
    string getFecha() const;
};

Llamada::Llamada(string numero)
{
    this->numero = numero;
    this->fecha = __DATE__;
    this->fecha += " ";
    this->fecha += __TIME__;
}

string Llamada::getNumero() const
{
    return numero;
}

string Llamada::getFecha() const
{
    return fecha;
}

class Llamadas
{
private:
    stack<Llamada> llamadas;

public:
    Llamadas();
    void agregarLlamada(Llamada llamada);
    void showLlamadas();
};

Llamadas::Llamadas()
{
}

void Llamadas::agregarLlamada(Llamada llamada)
{
    llamadas.push(llamada);
}

void Llamadas::showLlamadas()
{
    stack<Llamada> temp = llamadas;
    while (!temp.empty())
    {
        cout << "Numero LLamda: " << temp.top().getNumero() << endl;
        cout << "Fecha LLamada: " << temp.top().getFecha() << endl;
        cout << "----------------------" << endl;
        temp.pop();
    }
}

int main()
{
    Llamadas llamadas;
    string numero;
    int opcion = 0;
    do
    {
        cout << "1. Agregar llamada" << endl;
        cout << "2. Mostrar llamadas" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";

        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion)
        {
        case 1:
            cout << "Ingrese el numero a llamar: ";
            getline(cin, numero);
            llamadas.agregarLlamada(Llamada(numero));
            break;
        case 2:
            llamadas.showLlamadas();
            break;
        default:
            break;
        }

    } while (opcion != 0);

    return 0;
}