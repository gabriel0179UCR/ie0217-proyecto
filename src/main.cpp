#include <iostream>
#include <string>
#include <sqlite3.h>
#include "Scripts\Client.hpp"
#include "Scripts\Verifier.hpp"
using namespace std;
// g++ main.cpp Scripts\Client.cpp Scripts\Verifier.cpp Scripts\Manage_SQL_Queries.cpp -o test -IC:\sqlite -LC:\sqlite -lsqlite3
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
    bool exitPrincipalMenu = false;
    bool exitSecundaryMenu = false;
    int clientID = 0;
    string clientName;

    sqlite3 *db;
    int rc;
    rc = sqlite3_open("Database\\banco_ie0217_db.db", &db);

    while(!exitPrincipalMenu) {
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
            exitSecundaryMenu = false;
            break;
        case ADDCLIENT:
            cout << "Agregue el nombre del cliente: ";
            cin >> clientName;
            exitSecundaryMenu = false;
            break;
        case EXIT:
            exitPrincipalMenu = true;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            exitSecundaryMenu = true;
        };

        while (!exitSecundaryMenu){
            Client client(clientID);
            Verifier verifier(clientID);

            cout << endl << "///// Acciones /////" << endl;
            cout << "1. Depositar" << endl;
            cout << "2. Retirar" << endl;
            cout << "3. Salir al menú principal" << endl;

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
                if (verifier.moneyAvailable(db, denomination, quantity)) {
                    client.retire(db, denomination, quantity);
                } else {
                    cout << "Monto a retirar es mayor al monto de la cuenta" << endl;
                }
                break;
            case EXIT:
                cout << "Saliendo al menu principal" << endl;
                exitSecundaryMenu = true;
                break;
            }
        }

    }


    

    sqlite3_close(db);

    return 0;
}