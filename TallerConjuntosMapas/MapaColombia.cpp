#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class InfoDepartamento
{
private:
    string ciudad;
    string departamento;
    string clima;

public:
    InfoDepartamento();
    InfoDepartamento(string ciudad, string departamento, string clima);

public:
    string getCiudad() const;
    void setCiudad(string ciudad);
    string getDepartamento() const;
    void setDepartamento(string departamento);
    string getClima() const;
    void setClima(string clima);

    void showInfo() const;
};

InfoDepartamento::InfoDepartamento()
{
}

InfoDepartamento::InfoDepartamento(string ciudad, string departamento, string clima)
{
    this->ciudad = ciudad;
    this->departamento = departamento;
    this->clima = clima;
}

string InfoDepartamento::getCiudad() const
{
    return ciudad;
}

void InfoDepartamento::setCiudad(string ciudad)
{
    this->ciudad = ciudad;
}

string InfoDepartamento::getDepartamento() const
{
    return departamento;
}

void InfoDepartamento::setDepartamento(string departamento)
{
    this->departamento = departamento;
}

string InfoDepartamento::getClima() const
{
    return this->clima;
}

void InfoDepartamento::setClima(string clima)
{
    this->clima = clima;
}

void InfoDepartamento::showInfo() const
{
    cout << " ------------------- Info -------------------" << endl;
    if (!this->ciudad.empty() && !this->departamento.empty() && !this->clima.empty())
    {
        cout << "Ciudad: " << this->ciudad << endl;
        cout << "Departamento: " << this->departamento << endl;
        cout << "Clima: " << this->clima << endl;
    }
    else
    {
        cout << "Informacion del departamento no encontrada" << endl;
    }
    cout << " -------------------------------------------" << endl;
}

class Codazi
{
private:
    map<string, string> colombia;
    map<string, string> clima;

public:
    Codazi();
    InfoDepartamento buscarDepartamento();
    vector<InfoDepartamento> buscarDepartamentosPorClima();
};

Codazi::Codazi()
{
    this->colombia.insert({"antioquia", "medellin"});
    this->colombia.insert({"bogota d.c.", "bogota"});
    this->colombia.insert({"valle del cauca", "cali"});
    this->colombia.insert({"atlantico", "barranquilla"});
    this->colombia.insert({"santander", "bucaramanga"});
    this->colombia.insert({"cundinamarca", "bogota"});
    this->colombia.insert({"nariño", "pasto"});
    this->colombia.insert({"cordoba", "monteria"});
    this->colombia.insert({"tolima", "ibague"});
    this->colombia.insert({"magdalena", "santa marta"});
    this->colombia.insert({"amazonas", "leticia"});
    this->colombia.insert({"antioquia", "medellin"});
    this->colombia.insert({"arauca", "arauca"});
    this->colombia.insert({"atlantico", "barranquilla"});
    this->colombia.insert({"bolivar", "cartagena"});
    this->colombia.insert({"boyaca", "tunja"});
    this->colombia.insert({"caldas", "manizales"});
    this->colombia.insert({"caqueta", "florencia"});
    this->colombia.insert({"casanare", "yopal"});
    this->colombia.insert({"cauca", "popayan"});
    this->colombia.insert({"cesar", "valledupar"});
    this->colombia.insert({"choco", "quibdo"});
    this->colombia.insert({"cordoba", "monteria"});
    this->colombia.insert({"cundinamarca", "bogota"});
    this->colombia.insert({"guainia", "inirida"});
    this->colombia.insert({"guaviare", "san jose del guaviare"});
    this->colombia.insert({"huila", "neiva"});
    this->colombia.insert({"la guajira", "riohacha"});
    this->colombia.insert({"magdalena", "santa marta"});
    this->colombia.insert({"meta", "villavicencio"});
    this->colombia.insert({"nariño", "pasto"});
    this->colombia.insert({"norte de santander", "cucuta"});
    this->colombia.insert({"putumayo", "mocoa"});
    this->colombia.insert({"quindio", "armenia"});
    this->colombia.insert({"risaralda", "pereira"});
    this->colombia.insert({"san andres y providencia", "san andres"});
    this->colombia.insert({"santander", "bucaramanga"});
    this->colombia.insert({"sucre", "sincelejo"});
    this->colombia.insert({"tolima", "ibague"});
    this->colombia.insert({"valle del cauca", "cali"});
    this->colombia.insert({"vaupes", "mitu"});
    this->colombia.insert({"vichada", "puerto carreno"});

    // capital - clima
    map<string, string> clima;
    this->clima.insert({"medellin", "templado"});
    this->clima.insert({"bogota", "frio"});
    this->clima.insert({"cali", "caliente"});
    this->clima.insert({"barranquilla", "caliente"});
    this->clima.insert({"bucaramanga", "templado"});
    this->clima.insert({"pasto", "frio"});
    this->clima.insert({"monteria", "caliente"});
    this->clima.insert({"ibague", "templado"});
    this->clima.insert({"santa marta", "caliente"});
    this->clima.insert({"leticia", "caliente"});
    this->clima.insert({"arauca", "caliente"});
    this->clima.insert({"cartagena", "caliente"});
    this->clima.insert({"tunja", "frio"});
    this->clima.insert({"manizales", "frio"});
    this->clima.insert({"florencia", "caliente"});
    this->clima.insert({"yopal", "caliente"});
    this->clima.insert({"popayan", "templado"});
    this->clima.insert({"valledupar", "caliente"});
    this->clima.insert({"quibdo", "caliente"});
    this->clima.insert({"inirida", "caliente"});
    this->clima.insert({"san jose del guaviare", "caliente"});
    this->clima.insert({"neiva", "caliente"});
    this->clima.insert({"riohacha", "caliente"});
    this->clima.insert({"villavicencio", "caliente"});
    this->clima.insert({"cucuta", "caliente"});
    this->clima.insert({"mocoa", "caliente"});
    this->clima.insert({"armenia", "templado"});
    this->clima.insert({"pereira", "templado"});
    this->clima.insert({"san andres", "caliente"});
    this->clima.insert({"sincelejo", "caliente"});
    this->clima.insert({"mitu", "caliente"});
    this->clima.insert({"puerto carreno", "caliente"});
}

InfoDepartamento Codazi::buscarDepartamento()
{
    InfoDepartamento info;
    string departamento;
    cout << "Ingrese el nombre del departamento: ";
    cin >> departamento;

    map<string, string>::iterator it = this->colombia.find(departamento);
    if (it != this->colombia.end())
    {
        info = InfoDepartamento(it->second, it->first, this->clima[it->second]);
    }
    return info;
}

vector<InfoDepartamento> Codazi::buscarDepartamentosPorClima()
{
    vector<InfoDepartamento> departamentos;
    string clima;
    cout << "Ingrese el clima: ";
    cin >> clima;

    for (map<string, string>::iterator it = this->clima.begin(); it != this->clima.end(); it++)
    {
        if (it->second == clima)
        {
            map<string, string>::iterator itCol = find_if(this->colombia.begin(), this->colombia.end(), [it](pair<string, string> p)
                                                          { return p.second == it->first; });
            if (itCol != this->colombia.end())
            {
                departamentos.push_back(InfoDepartamento(it->first, itCol->first, it->second));
            }
        }
    }
    return departamentos;
}

int main(int argc, char const *argv[])
{

    int opcion = 0;
    Codazi codazi;
    vector<InfoDepartamento> infoDepartamentos;
    do
    {
        cout << "1. Buscar informacion por departamento" << endl;
        cout << "2. Buscar informacion departamentos segun el clima" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            codazi.buscarDepartamento().showInfo();
            break;
        case 2:
            infoDepartamentos = codazi.buscarDepartamentosPorClima();
            if (infoDepartamentos.empty())
            {
                cout << "No se encontraron departamentos." << endl;
                break;
            }
            for (InfoDepartamento info : infoDepartamentos)
            {
                info.showInfo();
            }
            break;
        default:
            opcion = 0;
            break;
        }
    } while (opcion != 0);

    return 0;
}
