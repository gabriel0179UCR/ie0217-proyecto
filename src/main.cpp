#include <iostream>
#include <string>
#include <sqlite3.h>
#include "Scripts\Client.hpp"
#include "Scripts\Verifier.hpp"
using namespace std;
// g++ main.cpp Scripts\Client.cpp Scripts\Verifier.cpp Scripts\Manage_SQL_Queries.cpp -o test -IC:\sqlite -LC:\sqlite -lsqlite3

//! Estructura del menu principal
enum ClientEnter {
    ENTERCLIENT = 1,
    ADDCLIENT,
    EXITPRINCIPAL
};

//! Estructura del menu secundario
enum ClientOptions {
    DEPOSIT = 1,
    RETIRE,
    TRANSFER,
    TRANSACTIONS,
    LOANS_MENU,
    CDP,
    EXITSECUNDARY
};

int main_menu(){
    int option;
    // Menu principal
    cout << endl << "///// Sistema de gestion bancaria /////" << endl;
    cout << "1. Ingresar cliente" << endl;
    cout << "2. Agregar cliente" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese su opcion: ";
    cin >> option;

    return option;
};

int secundary_menu(){
    int option;
    cout << endl << "///// Acciones /////" << endl;
    cout << "1. Depositar" << endl;
    cout << "2. Retirar" << endl;
    cout << "3. Transferir" << endl;
    cout << "4. Registro de transacciones" << endl;
    cout << "5. Menu de prestamos" << endl;
    cout << "6. Solicitar CDP" << endl;
    cout << "7. Salir al menu principal" << endl;

    cout << "Ingrese su opcion: ";
    cin >> option;

    return option;
};

int loan_menu(){
    int option;
    cout << endl << "///// Acciones /////" << endl;
    cout << "1. Informacion general de prestamos" << endl;
    cout << "2. Solicitar prestamo" << endl;
    cout << "3. Solicitar reporte de prestamos" << endl;
    cout << "4. Salir al menu secundario" << endl;

    cout << "Ingrese su opcion: ";
    cin >> option;

    return option;
}


int main() {
    int option;
    bool exitMainMenu = false;
    bool exitSecundaryMenu = false;
    int clientID = 0;
    int clientIDDest = 0;
    string clientName;

    sqlite3 *db;
    int rc;
    // Se establece conexion a la base de datos
    rc = sqlite3_open("Database\\banco_ie0217_db.db", &db);

    while(!exitMainMenu) {
        // Menu principal
        option = main_menu();
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
            clientID =createNewClient(db, clientName);
            exitSecundaryMenu = false;
            break;
        case EXITPRINCIPAL:
            exitMainMenu = true;
            return 0;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            exitSecundaryMenu = true;
        };

        while (!exitSecundaryMenu){
            Verifier verifier(clientID);
            if (!verifier.clientIdExist(db)) {
                cout << "ID de cliente no existe" << endl;
                break;
            }
            Client client(clientID, db);

            // Menu secundario
            option = secundary_menu();

            float quantity;
            string denominationSRC;
            string denominationDST;
            string denominationQuantity;

            switch (option)
            {
            case DEPOSIT:
                cout << "Ingrese la denominacion del monto: ";
                cin >> denominationSRC;
                cout << "Ingrese la denominacion de la cuenta: ";
                cin >> denominationDST;
                cout << "Ingrese el monto a depositar: ";
                cin >> quantity;

                client.deposit(db, denominationSRC, denominationDST, quantity);
                break;
            case RETIRE:
                cout << "Ingrese la denominacion del monto: ";
                cin >> denominationSRC;
                cout << "Ingrese la denominacion de la cuenta: ";
                cin >> denominationDST;
                cout << "Ingrese el monto a retirar: ";
                cin >> quantity;
                if (verifier.moneyAvailable(db, denominationDST, client.convertMoney(db, denominationSRC, denominationDST, quantity))) {
                    client.retire(db, denominationSRC, denominationDST, quantity);
                } else {
                    cout << "Monto a retirar es mayor al monto de la cuenta" << endl;
                }
                break;
            
            case TRANSFER:
                cout << "Ingrese la denominacion de la cuenta fuente: ";
                cin >> denominationSRC;
                cout << "Ingrese el ID del cliente destino: ";
                cin >> clientIDDest;
                cout << "Ingrese la denominacion de la destino: ";
                cin >> denominationDST;
                cout << "Ingrese la denominacion de la cantidad: ";
                cin >> denominationQuantity;
                cout << "Ingrese la cantidad: ";
                cin >> quantity;

                client.transfer(db, denominationSRC, clientIDDest, denominationDST, denominationQuantity, quantity);
                break;
            case TRANSACTIONS:
                cout << endl << "Resgistro de transacciones" << endl;
                client.transactions(db);
                break;

            case LOANS_MENU:
                // Menu de prestamos
                option = loan_menu();
                break;

            case CDP:
                break;
            
            case EXITSECUNDARY:
                cout << "Saliendo al menu principal" << endl;
                exitSecundaryMenu = true;
                break;
            }
        }
    }

    sqlite3_close(db);

    return 0;
}