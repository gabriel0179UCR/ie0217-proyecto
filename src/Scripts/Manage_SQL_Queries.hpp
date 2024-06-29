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
#endif