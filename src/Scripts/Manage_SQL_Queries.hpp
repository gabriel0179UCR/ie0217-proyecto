#ifndef MANAGESQLQUERIES_HPP
#define MANAGESQLQUERIES_HPP

#include <string>
using namespace std;

//! Declaracion de la funcion que permite almacenar el codigo de SQL en un string
string read_sql_file(const string& filename);

//! Declaracion de la funcion callback para la ejecucion de codigo de SQL general
int callback(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback que muestra la informacion general del cliente
int callback_Get_Client_Data(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para la ejecucion de codigo de SQL que verifica si hay dinero disponible en la cuenta
int callback_Verify_Money_Available(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para la ejecucion de codigo de SQL que verifica si existe el ID del cliente ingresado
int callback_Verify_ClientID_Exist(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para la ejecucion de codigo de SQL que convierte el dinero segun el tipo de cambio
int callback_Convert_Money(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para la ejecucion de codigo de SQL que crea un nuevo cliente en la base de datos
int callback_Create_New_Client(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para el metodo que deposita dinero en una cuenta
int callback_Deposit(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para el metodo que retira dinero en una cuenta
int callback_Retire(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para el metodo que transfiere dinero de una cuenta a otra
int callback_Transfer(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para el metodo que muestra el registro de transacciones
int callback_Transactions(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para la funcion que extrae informacion de prestamos
int callback_Get_Loans_Types(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para el metodo que crea prestamos a un usuario
int callback_Loan(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para el metodo que abona dinero a un prestamo
int callback_Loan_Payment(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para la funcion que consulta el interes de un prestamo
int callback_Get_Interest_Loan(void *data, int argc, char **argv, char **azColName);

//! Declaracion de la funcion callback para el metodo que crea CDPs
int callback_CDP(void *data, int argc, char **argv, char **azColName);

#endif