#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto {
    int id;
    string nombre;
    int cantidad;
    float precio;
};

vector<Producto> inventario;

void limpiarPantalla() {
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

void pausarPantalla() {
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void mostrarMenu() {
    cout << "\n========== Tienda Sara ==========\n";
    cout << "1. Ingresar nuevo producto\n";
    cout << "2. Vender producto\n";
    cout << "3. Consultar stock de un producto\n";
    cout << "4. Mostrar todos los productos en inventario\n";
    cout << "5. Salir\n";
    cout << "====================================\n";
}

void ingresarProducto() {
    char continuar;
    do {
        Producto p;
        cout << "Ingrese el ID del producto: ";
        cin >> p.id;
        cout << "Ingrese el nombre del producto: ";
        cin.ignore();
        getline(cin, p.nombre);
        cout << "Ingrese la cantidad del producto: ";
        cin >> p.cantidad;
        cout << "Ingrese el precio del producto: ";
        cin >> p.precio;

        inventario.push_back(p);
        cout << "Producto ingresado correctamente.\n";
        
        cout << "Desea ingresar otro producto? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');
    limpiarPantalla();
}

void venderProducto() {
    int id, cantidad;
    cout << "Ingrese ID del producto a vender: ";
    cin >> id;
    cout << "Ingrese cantidad a vender: ";
    cin >> cantidad;

    for (size_t i = 0; i < inventario.size(); ++i) {
        if (inventario[i].id == id) {
            if (inventario[i].cantidad >= cantidad) {
                float totalVenta = cantidad * inventario[i].precio;
                inventario[i].cantidad -= cantidad;
                cout << "Venta realizada correctamente.\n";
                cout << "Total de la venta: $" << totalVenta << endl;
            } else {
                cout << "Stock insuficiente.\n";
            }
            pausarPantalla();
            limpiarPantalla();
            return;
        }
    }
    cout << "Producto no encontrado.\n";
    pausarPantalla();
    limpiarPantalla();
}

void consultarStock() {
    int id;
    cout << "Ingrese ID del producto a consultar: ";
    cin >> id;

    for (size_t i = 0; i < inventario.size(); ++i) {
        if (inventario[i].id == id) {
            cout << "Producto: " << inventario[i].nombre << endl;
            cout << "Cantidad en stock: " << inventario[i].cantidad << endl;
            cout << "Precio: $" << inventario[i].precio << endl;
            pausarPantalla();
            limpiarPantalla();
            return;
        }
    }
    cout << "Producto no encontrado.\n";
    pausarPantalla();
    limpiarPantalla();
}

void mostrarInventario() {
    if (inventario.empty()) {
        cout << "No hay productos en el inventario.\n";
        pausarPantalla();
        limpiarPantalla();
        return;
    }

    cout << "\n========== Inventario de Productos ==========\n";
    for (size_t i = 0; i < inventario.size(); ++i) {
        cout << "ID: " << inventario[i].id << endl;
        cout << "Nombre: " << inventario[i].nombre << endl;
        cout << "Cantidad: " << inventario[i].cantidad << endl;
        cout << "Precio: $" << inventario[i].precio << endl;
        cout << "-------------------------------------------\n";
    }
    pausarPantalla();
    limpiarPantalla();
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarProducto();
                break;
            case 2:
                venderProducto();
                break;
            case 3:
                consultarStock();
                break;
            case 4:
                mostrarInventario();
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
                pausarPantalla();
                limpiarPantalla();
        }
    } while (opcion != 5);

    return 0;
}


