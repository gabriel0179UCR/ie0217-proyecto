#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <sqlite3.h>
#include <string>
using namespace std;

//! Declaracion de la clase Client
class Client {
    private:
        //! Atributo referenciado al ID del cliente
        int id;
    public:
        Client(int _id);
        virtual ~Client(){} // Destructor

        //! Declaracion del metodo que permite convertir el dinero en funcion del tipo de cambio
        float convertMoney(sqlite3 *db, string denominationSRC, string denominationDST, float quantity);

        //! Declaracion del metodo que permite depositar dinero en una cuenta
        void deposit(sqlite3 *db, string denominationSRC, string denominationDST, float quantity);

        //! Declaracion del metodo que permite retirar dinero de una cuenta
        void retire(sqlite3 *db, string denominationSRC, string denominationDST, float quantity);

        //! Declaracion del metodo que permite transferir entre cuentas  
        void transfer(sqlite3 *db, string denominationSRC, int idDST, string denominationDST, string denominationQuantit, float quantity);

        //! Declaracion del metodo que consulta el registro de transacciones
        void transactions(sqlite3 *db);

        //! Declaracion del metodo que permite crear prestamos al cliente
        void loan(sqlite3 *db, string loanType, string denomination, float quantity, int fee);
        
};

//! Declaracion de la funcion createNewClient que permite crear un nuevo cliente en la base de datos
int createNewClient(sqlite3 *db, string nombre);

#endif // CLIENT_HPP