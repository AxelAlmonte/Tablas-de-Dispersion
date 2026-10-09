/*

Grupo 1:
- Alessandro Salamone - 1132116
- Carlos Minaya - 1132836
- Axel Almonte - 1131078
- ⁠Octavio Ramírez - 1132995
- ⁠José Pinales - 1133255
- Christian Acosta - 1132698

*/

#include <iostream>

bool idValido(int id) 
{
    if (id > 0) 
    {
        return true;    // el ID es correcto
    }
    return false;       // el ID es incorrecto
}


int buscar(int id) 
{
    // Primero revisamos que el ID sea válido
    if (idValido(id) == false) 
    {
        cout << "ID invalido." << endl;
        return -1;
    }

    // La función hash nos dice dónde empezar a buscar
    int pos = hash(id);

    // Revisamos casilla por casilla (máximo TAM veces)
    for (int i = 0; i < TAM; i++) 
    {
        // Si la casilla está vacía, el ID no existe
        if (tabla[pos].ocupado == false) 
        {
            return -1;
        }
        // Si la casilla tiene el ID que buscamos, lo encontramos
        if (tabla[pos].id == id) 
        {
            return pos;
        }
        // Si no, pasamos a la siguiente casilla (y volvemos al inicio si llegamos al final)
        pos = (pos + 1) % TAM;
    }

    return -1;   // revisamos todo y no estaba
}

void mostrarTodo() 
{
    for (int i = 0; i < TAM; i++) 
    {
        if (tabla[i].ocupado == true) 
        {
            cout << "Posicion " << i << ": ID = " << tabla[i].id
                 << ", Nombre = " << tabla[i].nombre << endl;
        }         
        else   
        {
            cout << "Posicion " << i << ": vacia" << endl;
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
}
