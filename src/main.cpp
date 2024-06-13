#include <iostream>
#include <string>
#include <sqlite3.h>
#include "Scripts\Client.hpp"
using namespace std;

enum ClientEnter {
    ENTERCLIENT = 1,
    ADDCLIENT,
    EXIT
};

enum ClientOptions {
    DEPOSIT = 1,
    RETIRE
};

int main() {
    int option;
    bool exit = false;
    int clientID = 0;
    string clientName;

    sqlite3 *db;
    int rc;
    rc = sqlite3_open("Database\\banco_ie0217_db.db", &db);

    cout << endl << "///// Sistema de gestion bancaria /////" << endl;
    cout << "1. Ingresar cliente" << endl;
    cout << "2. Agregar cliente" << endl;
    cout << "3. Salir" << endl;
    
    cout << "Ingrese su opcion: ";
    cin >> option;
    switch (option)
    {
    case ENTERCLIENT:
        cout << "Ingrese el ID del cliente: ";
        cin >> clientID;
        break;
    case ADDCLIENT:
        cout << "Agregue el nombre del cliente: ";
        cin >> clientName;
        break;
    case EXIT:
        return 0;
        break;
    };
    Client client(clientID);

    cout << endl << "///// Acciones /////" << endl;
    cout << "1. Depositar" << endl;
    cout << "2. Retirar" << endl;
    cout << "3. Salir" << endl;
    
    cout << "Ingrese su opcion: ";
    cin >> option;

    int quantity;
    string denomination;

    switch (option)
    {
    case DEPOSIT:
        cout << "Ingrese la denominacion: ";
        cin >> denomination;
        cout << "Ingrese el monto a depositar: ";
        cin >> quantity;

        client.deposit(db, denomination, quantity);
        break;
    case RETIRE:
        cout << "Ingrese la denominacion: ";
        cin >> denomination;
        cout << "Ingrese el monto a retirar: ";
        cin >> quantity;

        client.retire(db, denomination, quantity);
        break;
        break;
    case EXIT:
        break;
    }

    sqlite3_close(db);

    return 0;
}