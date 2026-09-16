#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct nodoestudiante {
    string ci;
    string nombre;
    string apellido;
    int edad;
    char sexo;
    nodoestudiante* siguiente;
};

nodoestudiante* primero = NULL;
nodoestudiante* ultimo = NULL;

void iniciar() {
    primero = NULL;
    ultimo = NULL;
}

int vacia() {
    return (primero == NULL) ? 1 : 0;
}

void insertar_delante(string ci, string nomb, string apell, int edad, char sexo) {
    nodoestudiante* nodo = new nodoestudiante;
    nodo->ci = ci;
    nodo->nombre = nomb;
    nodo->apellido = apell;
    nodo->edad = edad;
    nodo->sexo = sexo;
    nodo->siguiente = NULL;

    if (vacia()) {
        primero = nodo;
        ultimo = nodo;
    }
    else {
        nodo->siguiente = primero;
        primero = nodo;
    }
}

void insertar_detras(string ci, string nomb, string apell, int edad, char sexo) {
    nodoestudiante* nodo = new nodoestudiante;
    nodo->ci = ci;
    nodo->nombre = nomb;
    nodo->apellido = apell;
    nodo->edad = edad;
    nodo->sexo = sexo;
    nodo->siguiente = NULL;

    if (vacia()) {
        primero = nodo;
        ultimo = nodo;
    }
    else {
        ultimo->siguiente = nodo;
        ultimo = nodo;
    }
}

void insertar_ordenadamente(string ci, string nomb, string apell, int edad, char sexo) {
    nodoestudiante* nodo = new nodoestudiante;
    nodo->ci = ci;
    nodo->nombre = nomb;
    nodo->apellido = apell;
    nodo->edad = edad;
    nodo->sexo = sexo;
    nodo->siguiente = NULL;

    if (vacia()) {
        primero = nodo;
        ultimo = nodo;
    }
    else {
        nodoestudiante* p = primero;
        nodoestudiante* q = primero;

        while ((p != NULL) && (p->ci < ci)) {
            q = p;
            p = p->siguiente;
        }

        if (p == primero) {
            nodo->siguiente = primero;
            primero = nodo;
        }
        else {
            q->siguiente = nodo;
            nodo->siguiente = p;
            if (p == NULL) {
                ultimo = nodo;
            }
        }
    }
}

void eliminar(string ci_eliminar) {
    if (vacia()) {
        cout << "La lista esta vacia.\n";
        return;
    }

    nodoestudiante* p = primero;
    nodoestudiante* q = primero;

    while ((p != NULL) && (p->ci != ci_eliminar)) {
        q = p;
        p = p->siguiente;
    }

    if (p == NULL) {
        cout << "No existe un estudiante con el CI ingresado.\n";
    }
    else {
        if (primero == ultimo) {
            delete p;
            iniciar();
        }
        else if (p == primero) {
            primero = primero->siguiente;
            delete p;
        }
        else if (p == ultimo) {
            ultimo = q;
            ultimo->siguiente = NULL;
            delete p;
        }
        else {
            q->siguiente = p->siguiente;
            delete p;
        }
        cout << "Estudiante eliminado correctamente.\n";
    }
}

void mostrar() {
    if (vacia()) {
        cout << "Lista vacia.\n";
        return;
    }
    nodoestudiante* p = primero;
    while (p != NULL) {
        cout << "CI: " << p->ci << " | Nombre: " << p->nombre << " " << p->apellido
            << " | Edad: " << p->edad << " | Sexo: " << p->sexo << endl;
        p = p->siguiente;
    }
}

void mostrar_total_estudiantes() {
    int cont = 0;
    nodoestudiante* p = primero;
    while (p != NULL) {
        cont++;
        p = p->siguiente;
    }
    cout << "Total de estudiantes registrados: " << cont << endl;
}

void estudiante_menor_edad() {
    if (vacia()) {
        cout << "Lista vacia.\n";
        return;
    }
    nodoestudiante* p = primero;
    nodoestudiante* menor_nodo = primero;
    int menor = primero->edad;

    while (p != NULL) {
        if (p->edad < menor) {
            menor = p->edad;
            menor_nodo = p;
        }
        p = p->siguiente;
    }

    cout << "Estudiante con menor edad (" << menor << " anos):\n";
    cout << "CI: " << menor_nodo->ci << " - " << menor_nodo->nombre << " " << menor_nodo->apellido << endl;
}

int main() {
    int opc;
    string ci, nombre, apellido;
    int edad;
    char sexo;

    iniciar();

    do {
        system("cls");
        cout << "=========================================\n";
        cout << "    LISTA SIMPLEMENTE ENLAZADA DE ESTUDIANTES\n";
        cout << "=========================================\n";
        cout << "1.- Insertar estudiante por delante\n";
        cout << "2.- Insertar estudiante por detras\n";
        cout << "3.- Insertar estudiante ordenadamente (por CI)\n";
        cout << "4.- Eliminar estudiante por CI\n";
        cout << "5.- Mostrar todos los estudiantes\n";
        cout << "6.- Total de estudiantes\n";
        cout << "7.- Estudiante con menor edad\n";
        cout << "8.- Salir\n";
        cout << "Opcion (1-8): ";
        cin >> opc;

        switch (opc) {
        case 1:
        case 2:
        case 3:
            cout << "\n--- Ingrese Datos del Estudiante ---\n";
            cout << "CI: "; cin >> ci;
            cin.ignore();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Apellido: "; getline(cin, apellido);
            cout << "Edad: "; cin >> edad;
            cout << "Sexo (M/F): "; cin >> sexo;

            if (opc == 1) insertar_delante(ci, nombre, apellido, edad, sexo);
            else if (opc == 2) insertar_detras(ci, nombre, apellido, edad, sexo);
            else insertar_ordenadamente(ci, nombre, apellido, edad, sexo);

            system("pause");
            break;

        case 4:
            cout << "Ingrese el CI del estudiante a eliminar: ";
            cin >> ci;
            eliminar(ci);
            system("pause");
            break;

        case 5:
            cout << "\n--- Lista de Estudiantes ---\n";
            mostrar();
            system("pause");
            break;

        case 6:
            mostrar_total_estudiantes();
            system("pause");
            break;

        case 7:
            estudiante_menor_edad();
            system("pause");
            break;

        case 8:
            cout << "Saliendo del programa...\n";
            break;
        }
    } while (opc != 8);

    return 0;
}