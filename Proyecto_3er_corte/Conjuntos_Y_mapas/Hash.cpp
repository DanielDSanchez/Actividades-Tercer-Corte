#include <iostream>
using namespace std;

unsigned int SimpleHash(const string input)
{
    unsigned int hash = 0;
    for (char c : input)
    {
        hash += static_cast<unsigned int>(c);
    }
    return hash;
}

int main(int argc, char const *argv[])
{
    string input = "Programar es algo cool";
    unsigned int hashValue = SimpleHash(input);
    cout << "Datos de entrada: " << input << endl;
    cout << "Valor hash: " << hashValue << endl;
    return 0;
}
