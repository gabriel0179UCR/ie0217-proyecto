#ifndef VERIFIER_HPP
#define VERIFIER_HPP

#include <string>
#include <sqlite3.h>
using namespace std;

//! Declaracion de la clase Verifier
class Verifier{
    private:
        //! Atributo que hace referencia al ID del cliente
        int clientID;
        //! Atributo que hace referencia a la cantidad de dinero en la cuenta
        float quantity;
        //! Atributo que hace referencia a la denominacion de la cuenta
        string denomination;
    public:
        //! Constructor
        Verifier(int _id);
        //! Destructor
        virtual ~Verifier(){}
        //! Declaracion del metodo que verifica si el ID del cliente existe en la base de datos
        bool clientIdExist(sqlite3 *db);
        //! Declaracion del metodo que verifica si hay dinero disponible en la cuenta
        bool moneyAvailable(sqlite3 *db, string _denomination, float _quantity);
};

#endif // VERIFIER_HPP