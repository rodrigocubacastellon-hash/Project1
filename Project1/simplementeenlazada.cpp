// Lista Simplemente Enlazada de Estudiantes.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

struct nodoestudiante {
    string ci;
    string nombre;
    string apellido;
    int edad;
    char sexo;
    struct nodoestudiante* siguiente;
};

nodoestudiante* primero, * ultimo;

void iniciar()
{
    primero = NULL;
    ultimo = NULL;
}

int vacia()
{
    if (primero == NULL)
        return 1;
    else
        return 0;
}

void insertar_delante(string ci, string nomb, string apell, int ed, char sx)
{
    nodoestudiante* nodo;
    nodo = new nodoestudiante;
    nodo->siguiente = NULL;
    nodo->ci = ci;
    nodo->nombre = nomb;
    nodo->apellido = apell;
    nodo->edad = ed;
    nodo->sexo = sx;

    if (vacia())
    {
        primero = nodo;
        ultimo = nodo;
    }
    else
    {
        nodo->siguiente = primero;
        primero = nodo;
    }
    return;
}

void insertar_detras(string ci, string nomb, string apell, int ed, char sx)
{
    nodoestudiante* nodo;
    nodo = new nodoestudiante;
    nodo->siguiente = NULL;
    nodo->ci = ci;
    nodo->nombre = nomb;
    nodo->apellido = apell;
    nodo->edad = ed;
    nodo->sexo = sx;

    if (vacia())
    {
        primero = nodo;
        ultimo = nodo;
    }
    else
    {
        ultimo->siguiente = nodo;
        ultimo = nodo;
    }
    return;
}

int insertar_ordenadamente(string ci, string nomb, string apell, int ed, char sx)
{
    nodoestudiante* nodo, * p, * q;
    nodo = new nodoestudiante;
    nodo->siguiente = NULL;
    nodo->ci = ci;
    nodo->nombre = nomb;
    nodo->apellido = apell;
    nodo->edad = ed;
    nodo->sexo = sx;

    if (vacia())
    {
        primero = nodo;
        ultimo = nodo;
    }
    else
    {
        p = primero;
        q = primero;
        while ((p != NULL) && (p->ci < ci))
        {
            q = p;
            p = p->siguiente;
        }
        if (p == primero)
        {
            nodo->siguiente = primero;
            primero = nodo;
        }
        else
        {
            q->siguiente = nodo;
            nodo->siguiente = p;
            if (p == NULL)
                ultimo = nodo;
        }
    }
    return 0;
}

void mostrar()
{
    nodoestudiante* p;
    if (vacia())
        cout << "Lista vacia" << endl;
    else
    {
        p = primero;
        while (p != NULL) {
            cout << "CI: " << p->ci << endl;
            cout << "Nombre: " << p->nombre << endl;
            cout << "Apellido: " << p->apellido << endl;
            cout << "Edad: " << p->edad << endl;
            cout << "Sexo: " << p->sexo << endl;
            cout << "-----------------------" << endl;
            p = p->siguiente;
        }
        (void)getchar();
    }
    return;
}

void mostrar_for()
{
    nodoestudiante* p;
    if (vacia())
        cout << "Lista vacia" << endl;
    else
    {
        int i;
        p = primero;
        for (i = 1; p != NULL; i++) {
            cout << "Estudiante " << i << ":" << endl;
            cout << "CI: " << p->ci << endl;
            cout << "Nombre: " << p->nombre << endl;
            cout << "Apellido: " << p->apellido << endl;
            cout << "Edad: " << p->edad << endl;
            cout << "Sexo: " << p->sexo << endl;
            cout << "-----------------------" << endl;
            p = p->siguiente;
        }
        (void)getchar();
    }
    return;
}

void mostrar_total_estudiantes()
{
    nodoestudiante* p;
    int cont = 0;
    if (vacia())
        cout << "Lista vacia" << endl;
    else
    {
        p = primero;
        while (p != NULL) {
            cont = cont + 1;
            p = p->siguiente;
        }
        cout << "Total de estudiantes es: " << cont << endl;
        (void)getchar();
    }
    return;
}

void eliminar(string valor)
{
    nodoestudiante* p, * q;
    q = primero;
    p = primero;
    while ((p != NULL) && (p->ci != valor))
    {
        q = p;
        p = p->siguiente;
    }
    if (p == NULL)
        cout << "No existe ese elemento en la lista" << endl;
    else
    {
        if (primero == ultimo)
        {
            iniciar();
        }
        else
        {
            if (p == primero)
                primero = p->siguiente;
            else if (p == ultimo)
                ultimo = q;
            else
                q->siguiente = p->siguiente;
        }
        delete p;
    }
    return;
}

int main()
{
    string ci = "", nombre = "", apellido = "", c = "";
    int edad = 0;
    char sexo = ' ';
    int opc;

    iniciar();

    do
    {
        system("cls");
        cout << "           LISTA DE ESTUDIANTES (LSE)" << endl;
        cout << "      Seleccione la opcion a realizar\n\n";
        cout << "      1.- Insertar un estudiante por delante\n";
        cout << "      2.- Insertar un estudiante por detras\n";
        cout << "      3.- Insertar un estudiante ordenadamente\n";
        cout << "      4.- Eliminar un estudiante\n";
        cout << "      5.- Mostrar toda la lista de estudiantes\n";
        cout << "      6.- Mostrar toda la lista utilizando un for\n";
        cout << "      7.- Total de estudiantes\n";
        cout << "      8.- Salir\n";
        cout << "       \n\nOpcion(1-8): ";

        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << "Entre los Datos del Estudiante:\n";
            cout << "CI: "; cin >> ci;
            cout << "Nombre: "; cin >> nombre;
            cout << "Apellido: "; cin >> apellido;
            cout << "Edad: "; cin >> edad;
            cout << "Sexo (M/F): "; cin >> sexo;
            insertar_delante(ci, nombre, apellido, edad, sexo);
            break;
        case 2:
            cout << "Entre los Datos del Estudiante:\n";
            cout << "CI: "; cin >> ci;
            cout << "Nombre: "; cin >> nombre;
            cout << "Apellido: "; cin >> apellido;
            cout << "Edad: "; cin >> edad;
            cout << "Sexo (M/F): "; cin >> sexo;
            insertar_detras(ci, nombre, apellido, edad, sexo);
            break;
        case 3:
            cout << "Entre los Datos del Estudiante:\n";
            cout << "CI: "; cin >> ci;
            cout << "Nombre: "; cin >> nombre;
            cout << "Apellido: "; cin >> apellido;
            cout << "Edad: "; cin >> edad;
            cout << "Sexo (M/F): "; cin >> sexo;
            insertar_ordenadamente(ci, nombre, apellido, edad, sexo);
            break;
        case 4:
            cout << "CI del estudiante a eliminar: ";
            cin >> c;
            eliminar(c);
            (void)getchar();
            break;
        case 5:
            mostrar();
            cout << "Oprima una tecla para salir";
            (void)getchar();
            break;
        case 6:
            mostrar_for();
            cout << "Oprima una tecla para salir";
            (void)getchar();
            break;
        case 7:
            mostrar_total_estudiantes();
            cout << "Oprima una tecla para salir";
            (void)getchar();
            break;
        case 8:
            exit(0);
            break;
        }
    } while (opc != 8);

    return 0;
}