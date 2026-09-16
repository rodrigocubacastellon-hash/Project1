#include <iostream>
using namespace std;

class MaquinaExpendedora {
private:
    int montoRecaudado;

public:
    int costoProducto;
    int cantidadProducto;
    int divisiones;
    int numeroSocalos;

    MaquinaExpendedora() {
        montoRecaudado = 0;
        costoProducto = 0;
        cantidadProducto = 0;
        divisiones = 0;
        numeroSocalos = 0;
    }

    MaquinaExpendedora(int monto, int costo, int cantidad, int divs, int socalos) {
        montoRecaudado = monto;
        costoProducto = costo;
        cantidadProducto = cantidad;
        divisiones = divs;
        numeroSocalos = socalos;
    }

    int Vender(int pago) {
        if (cantidadProducto <= 0) {
            cout << "No hay productos disponibles.\n";
            return pago;
        }
        if (pago < costoProducto) {
            cout << "Pago insuficiente. Faltan " << (costoProducto - pago) << "\n";
            return pago;
        }

        int vuelto = pago - costoProducto;
        montoRecaudado += costoProducto;
        cantidadProducto--;
        cout << "Producto vendido correctamente.\n";
        return vuelto;
    }

    void Recargar(int cantidad) {
        cantidadProducto += cantidad;
        cout << "Se recargaron " << cantidad << " productos.\n";
    }

    void Visualizar() {
        cout << "\n----- ESTADO DE LA MAQUINA -----\n";
        cout << "MontoRecaudado:    " << montoRecaudado << "\n";
        cout << "CostoProducto:     " << costoProducto << "\n";
        cout << "CantidadProducto:  " << cantidadProducto << "\n";
        cout << "Divisiones:        " << divisiones << "\n";
        cout << "NumeroSocalos:     " << numeroSocalos << "\n";
        cout << "---------------------------------\n";
    }
