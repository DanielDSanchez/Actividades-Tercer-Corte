#include <iostream>
#include <string>
#include <queue>
#include <limits>

using namespace std;

class Persona
{
private:
    int posicion;
    int missingPosicion;
    string nombre;

public:
    Persona();
    Persona(int posicion);
    int getPosicion() const;
    void setPosition(int posicion);
    int getMissingPosicion() const;
    void setMissingPosicionPosicion(int halfPosicion);
    void show();
    string getNombre() const;
};

Persona::Persona()
{
}

Persona::Persona(int posicion)
{
    this->posicion = posicion;
    cout << "Ingrese el nombre de la persona: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombre);
}

int Persona::getPosicion() const
{
    return posicion;
}

void Persona::setPosition(int posicion)
{
    this->posicion = posicion;
}

int Persona::getMissingPosicion() const
{
    return missingPosicion;
}

void Persona::setMissingPosicionPosicion(int halfPosicion)
{
    this->missingPosicion = halfPosicion;
}

void Persona::show()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Posicion: " << posicion << endl;
    cout << "Posiciones faltantes para salir de la fila: " << missingPosicion << endl;
}

string Persona::getNombre() const
{
    return nombre;
}

class Fila
{
private:
    queue<Persona *> personas;

public:
    Fila();
    void addPersona();
    void showFila();
    void avanzarFila();
};

Fila::Fila()
{
}

void Fila::addPersona()
{
    Persona *persona = new Persona(personas.size() + 1);
    persona->setMissingPosicionPosicion(personas.size());
    personas.push(persona);
}

void Fila::showFila()
{
    queue<Persona *> temp = personas;
    cout << "--------- Fila de personas --------" << endl;
    if (personas.empty())
    {
        cout << "La fila esta vacia" << endl;
    }
    else
    {

        while (!temp.empty())
        {
            temp.front()->show();
            cout << "----------------------" << endl;
            temp.pop();
        }
    }
}

void Fila::avanzarFila()
{
    if (!personas.empty())
    {
        Persona *persona = personas.front();
        cout << "La persona que sale de la fila es: " << persona->getNombre() << endl;
        personas.pop();
    }

    queue<Persona *> temp = personas;
    while (!temp.empty())
    {
        Persona *persona = temp.front();
        persona->setMissingPosicionPosicion(persona->getMissingPosicion() - 1);
        persona->setPosition(persona->getPosicion() - 1);
        temp.pop();
    }
}

int main(int argc, char const *argv[])
{
    Fila fila;
    int opcion = 0;

    do
    {
        cout << "1. Agregar persona" << endl;
        cout << "2. Mostrar fila" << endl;
        cout << "3. Avanzar fila" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            fila.addPersona();
            break;
        case 2:
            fila.showFila();
            break;
        case 3:
            fila.avanzarFila();
            break;
        default:
            opcion = 0;
            break;
        }

    } while (opcion != 0);
    return 0;
}
