#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class CalificacionesURosario
{
private:
    // estudiante - asignaturas
    map<string, vector<string>> estudiantes;
    // asignatura - (estudiante - calificacion)
    map<string, map<string, int>> asignaturas;

public:
    CalificacionesURosario();
    void addCalificacion();
    void notaAsignaturaEstudiante();
    void showEstudiantes();
    void avgNotasEstudianete();
    void avgNotasAsignatura();
};

CalificacionesURosario::CalificacionesURosario()
{
}

void CalificacionesURosario::showEstudiantes()
{
    cout << "Estudiantes: " << endl;
    for (map<string, vector<string>>::iterator it = this->estudiantes.begin(); it != this->estudiantes.end(); it++)
    {
        cout << it->first << endl;
    }
}
void CalificacionesURosario::addCalificacion()
{
    string estudiante;
    string asignatura;
    int calificacion;

    cout << "Estudiante: ";
    cin >> estudiante;
    cout << "Asignatura: ";
    cin >> asignatura;
    cout << "Calificacion: ";
    cin >> calificacion;

    this->estudiantes[estudiante].push_back(asignatura);
    this->asignaturas.insert({asignatura, {{estudiante, calificacion}}});
}

void CalificacionesURosario::notaAsignaturaEstudiante()
{
    showEstudiantes();

    string estudiante;
    cout << "Ingrese el nombre del estudiante para ver sus asignaturas: ";
    cin >> estudiante;
    map<string, vector<string>>::iterator it = this->estudiantes.find(estudiante);
    if (it != this->estudiantes.end())
    {
        cout << "Asignaturas: " << endl;
        for (string asignatura : it->second)
        {
            cout << asignatura << endl;
        }
        string asignatura;
        cout << "Ingrese el nombre de la asignatura para ver la calificacion: ";
        cin >> asignatura;

        map<string, map<string, int>>::iterator itAsignatura = this->asignaturas.find(asignatura);
        if (itAsignatura != this->asignaturas.end())
        {
            int califacion = itAsignatura->second.find(estudiante)->second;
            cout << "Calificacion: " << califacion << endl;
        }
    }
}

void CalificacionesURosario::avgNotasEstudianete()
{
    showEstudiantes();

    string estudiante;
    cout << "Ingrese el nombre del estudiante para ver su promedio de notas ";
    cin >> estudiante;
    map<string, vector<string>>::iterator it = this->estudiantes.find(estudiante);
    if (it != this->estudiantes.end())
    {
        int sum = 0;
        int count = 0;
        for (string asignatura : it->second)
        {
            map<string, map<string, int>>::iterator itAsignatura = this->asignaturas.find(asignatura);
            if (itAsignatura != this->asignaturas.end())
            {
                sum += itAsignatura->second.find(estudiante)->second;
                count++;
            }
        }
        cout << "Promedio de notas: " << (sum / count) << endl;
    }
}

void CalificacionesURosario::avgNotasAsignatura()
{
    string asignatura;
    cout << "Ingrese el nombre de la asignatura para ver su promedio de notas ";
    cin >> asignatura;

    map<string, map<string, int>>::iterator itAsignatura = this->asignaturas.find(asignatura);
    if (itAsignatura != this->asignaturas.end())
    {
        int sum = 0;
        int count = 0;
        for (auto estudiante : itAsignatura->second)
        {
            sum += estudiante.second;
            count++;
        }
        cout << "Promedio de notas: " << (sum / count) << endl;
    }
}

int main(int argc, char const *argv[])
{
    CalificacionesURosario calificaciones;
    int opcion;
    do
    {
        cout << "1. Agregar calificacion" << endl;
        cout << "2. Ver nota de una asignatura de un estudiante" << endl;
        cout << "3. Promedio de notas de un estudiante" << endl;
        cout << "4. Promedio de notas de una asignatura" << endl;

        switch (opcion)
        {
        case 1:
            calificaciones.addCalificacion();
            break;
        case 2:
            calificaciones.notaAsignaturaEstudiante();
            break;
        case 3:
            calificaciones.avgNotasEstudianete();
            break;
        case 4:
            calificaciones.avgNotasAsignatura();
            break;
        default:
            opcion = 0;
            break;
        }
    } while (opcion != 0);

    return 0;
}
