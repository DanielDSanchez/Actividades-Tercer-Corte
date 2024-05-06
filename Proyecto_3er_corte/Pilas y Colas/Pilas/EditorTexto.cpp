#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

class EditorTexto
{
private:
    string text;
    stack<string> beforeText;
    stack<string> afterText;

public:
    EditorTexto();
    void setText(string &text);
    string getText() const;

    void addText();
    string deshacer();
    string rehacer();
};

EditorTexto::EditorTexto()
{
    text = "";
    beforeText.push(text);
}

void EditorTexto::setText(string &text)
{
    this->text = text;
    beforeText.push(text);
}

string EditorTexto::getText() const
{
    return text;
}

void EditorTexto::addText()
{
    string input;
    cout << "Ingrese el texto: ";
    getline(std::cin, input);
    this->text += input;
    beforeText.push(input);
}

string EditorTexto::deshacer()
{
    if (!beforeText.empty())
    {
        string text = beforeText.top();
        beforeText.pop();
        afterText.push(text);

        stack<string> temp = beforeText;
        string tmpText = "";
        while (!temp.empty())
        {
            tmpText += temp.top();
            temp.pop();
        }

        this->text = "";
        for (int i = tmpText.length(); i >= 0; i--)
        {
            this->text += tmpText[i];
        }

        return text;
    }
    return "";
}

string EditorTexto::rehacer()
{
    if (!afterText.empty())
    {
        string text = afterText.top();
        afterText.pop();
        beforeText.push(text);
        return this->text += text;
    }
    return "";
}

int main(int argc, char const *argv[])
{
    string text;
    int opcion = 0;
    EditorTexto editorTexto;

    do
    {
        cout << "1. Ingresar texto" << endl;
        cout << "2. Deshacer" << endl;
        cout << "3. Rehacer" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion)
        {
        case 1:
            editorTexto.addText();
            break;
        case 2:
            cout << "Texto deshecho: " << editorTexto.deshacer() << endl;
            cout << "Texto actual: " << editorTexto.getText() << endl;
            break;
        case 3:
            cout << "Texto rehecho: " << editorTexto.rehacer() << endl;
            cout << "Texto actual: " << editorTexto.getText() << endl;
            break;
        default:
            opcion = 0;
            cout << "Saliendo..." << endl;
            break;
        }

    } while (opcion != 0);

    return 0;
}
