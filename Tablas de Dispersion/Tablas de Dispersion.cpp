/*
Grupo 1:
- Alessandro Salamone - 1132116
- Carlos Minaya - 1132836
- Axel Almonte - 1131078
- ⁠Octavio Ramírez - 1132995
- ⁠José Pinales - 1133255
- Christian Acosta - 1132698

Hacer una tabla de dispercion usando una funcion hash para definir las keys en donde iran los estudiantes.
*/

#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

const int MAX = 31;

struct Estudiante {
    int id;
    string nombre;
    string carrera;
} tablaHash[MAX]; //Tabla hash donde tendra a todos los estudiantes organizados por keys.

//Tabla con los ids, nombres y carreras de los estudiantes
Estudiante estudiantes[MAX] = {
    {1132698, "Chirstian Javier Acosta Urena", "IDS"},
    {1131078, "Axel Martin Almonte Leon", "ICS"},
    {1129398, "Nathaniel Alvarez Bello", "IDS"},
    {1131528, "Rafael Jesus Arguelles Garcia", "SIS"},
    {1131946, "Diana Sophia Benoit Heredia", "SIS"},
    {1131460, "Samuel Enrique Bobea Diaz", "ICS"},
    {1132521, "Cesar Alonzo Bonilla Kunhardt", "ICS"},
    {1129997, "Victor Welvy Carrion De Jesus", "ICS"},
    {1132907, "Eduardo Luis De La Cruz Garcia", "IDS"},
    {1131489, "Karen Lisbeth Doñe Quezada", "SIS"},
    {1131689, "Arianna Lee Fernandez", "SIS"},
    {1132397, "Alejandro Jose Ferreras Fonfrias", "IDS"},
    {1132115, "Perla Nicole Goico Ceballos", "IDS"},
    {1132487, "Esteban Guzman Sanchez", "SIS"},
    {1132141, "Arnold Enrique Henriquez Nunez", "IDS"},
    {1131629, "Joel Arturo Jimenez Objio", "IDS"},
    {1130421, "Luis Sebastien Jimenez Perez", "ICS"},
    {1132836, "Carlos Alberto Minaya Gomez", "IDS"},
    {1132449, "Andy Ng Wu", "IDS"},
    {1132218, "Mario Steven Ozuna Trinidad", "ICS"},
    {1132407, "Ona Yumalai Perez Almonte", "IDS"},
    {1133255, "Jose Antonio Pinales Guzman", "IDS"},
    {1133244, "Gerardo Alexander Ramirez Lopez", "IDS"},
    {1132995, "Octavio Jose Ramirez Meran", "ICS"},
    {1131833, "Sebastian Ramirez Tejera", "IDS"},
    {1132706, "Alejandro Rodriguez Arredondo", "IDS"},
    {1132305, "Daniel De Jesus Rodriguez Hernandez", "SIS"},
    {1132116, "Alessandro Salamone Requena", "IDS"},
    {1132788, "Angel Eduardo Salcedo Rodriguez", "IDS"},
    {1131403, "Enger Ernesto Sanchez Plasencia", "ICS"},
    {1130761, "Marcos Segura Santana", "ICS"}
};

bool keysGeneradas = false;

// Generar indice inicial
int funcionHash(int id)
{
    return (id * 13) % MAX;
}

// Generar las keys de los estudiantes
void generarKeys()
{
    // Limpiar la tabla
    for (int i = 0; i < MAX; i++)
    {
        tablaHash[i].id = 0;
        tablaHash[i].nombre = "";
        tablaHash[i].carrera = "";
    }

    // Asignar las keys
    for (int i = 0; i < MAX; i++)
    {
        int key = funcionHash(estudiantes[i].id);

        // Resolver colisiones
        while (tablaHash[key].id != 0)
        {
            key = (key + 1) % MAX;
        }

        tablaHash[key] = estudiantes[i];
    }

    keysGeneradas = true;

    cout << "\nKeys generadas correctamente.\n\n";
}

// Desplegar la tabla hash
void mostrarTabla()
{
    if (!keysGeneradas)
    {
        cout << "\nPrimero debe generar las keys.\n\n";
        return;
    }

    cout << "\n====== Estudiantes ======\n";

    for (int i = 0; i < MAX; i++)
    {
        cout << "\nKey: " << i << endl;
        cout << "ID: " << tablaHash[i].id << endl;
        cout << "Nombre: " << tablaHash[i].nombre << endl;
        cout << "Carrera: " << tablaHash[i].carrera << endl;
    }

    cout << endl;
}

// Buscar estudiante por ID
void buscarEstudiante(int id)
{
    if (!keysGeneradas)
    {
        cout << "\nPrimero debe generar las keys.\n\n";
        return;
    }

    int key = funcionHash(id);

    for (int i = 0; i < MAX; i++)
    {
        if (tablaHash[key].id == id)
        {
            cout << "\n====== Estudiante encontrado ======\n";
            cout << "ID: " << tablaHash[key].id << endl;
            cout << "Nombre: " << tablaHash[key].nombre << endl;
            cout << "Carrera: " << tablaHash[key].carrera << endl;
            cout << "Key: " << key << "\n\n";
            return;
        }

        key = (key + 1) % MAX;
    }

    cout << "\nEl ID no pertenece a la clase.\n\n";
}

// Validar entrada numerica
void leerEntero(string mensaje, int& pDato)
{
    string datoString;
    size_t position;
    bool error;

    do
    {
        try
        {
            cout << mensaje;
            cin >> datoString;
            pDato = stoi(datoString, &position);

            if (datoString.length() != position)
            {
                error = true;
                cout << "Entrada invalida, ingrese un numero entero\n\n";
            }
            else
            {
                error = false;
            }
        }
        catch (const exception&)
        {
            error = true;
            cout << "Entrada invalida, ingrese un numero entero\n\n";
        }

    } while (error);
}

bool idValido(int id) 
{
    if (id > 0) 
    {
        return true;    // el ID es correcto
    }
    return false;       // el ID es incorrecto
}

int main()
{
    bool continuar = true;

    while (continuar)
    {
        cout << "====== Tabla Hash ======\n\n";
        cout << "1. Generar keys\n";
        cout << "2. Desplegar\n";
        cout << "3. Buscar\n";
        cout << "4. Salir\n\n";

        int opcion;
        leerEntero("Elija una opcion: ", opcion);

        switch (opcion)
        {
        case 1:
            generarKeys();
            break;

        case 2:
            mostrarTabla();
            break;

        case 3:
        {
            int id;
            leerEntero("\nIngrese el ID: ", id);
            buscarEstudiante(id);
            break;
        }

        case 4:
            continuar = false;
            break;

        default:
            cout << "\nOpcion invalida.\n\n";
            break;
        }
        cout << "Presione Enter para continuar.";
        _getch();
        system("cls");
    }
}
