// Michael Arturo Contreras Gilpin - 23310174 - 2P

// ******************************************************************************************
// Un "Smart Pointer" es un objeto en programación que actua como un puntero cualquiera, con 
// la característica de que añade valores adicionales para gestionar la memoria de manera más 
// segura y eficiente. Ayuda a evitar problemas comumes como fugas de memoria al liberar
// automáticamente la memoria cuando ya no es necesaria.
// ******************************************************************************************

#include <iostream>
#include <string>
#include <memory>
#include <fstream>

using namespace std;

class File {
private:

string name;

public:

// Constructor de la clase
File(const string& file_name) : name(file_name) {
    cout << "File created: " << name << endl;
}

// Se escribe el contenido en el archivo
void write(const string& content) {
    ofstream fileStream(name);
    fileStream << content;
    cout << "\nThis content was written into the file:" << endl;
    cout << content << endl;
}

// Destructor de la clase
~File() {
    cout << "\nFile closed: " << name << endl;
}
};

int main() {
    // Se le solicita al usuario el nombre del archivo
    string file_name_user;
    cout << "What is going to be the name of the file?" << endl;
    getline (cin, file_name_user);
    string full_name_file = file_name_user + ".txt";
    
    // Crea un objeto, a partir del Smart Pointer
    unique_ptr<File> filePtr =
    make_unique<File>(full_name_file);

    // Se le solicita al usuario ingresar lo que se añadirá al archivo
    string edit_file;
    cout << "\nWhat do you want to write into the file?" << endl;
    getline (cin, edit_file);

    // Escribe el contenido al archivo
    filePtr->write(edit_file);

    // No es necesario liberar espacio, puesto a que "unique_ptr" lo hace de manera automática

    return 0;
}