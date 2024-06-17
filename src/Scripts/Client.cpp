#include <iostream>
#include <sqlite3.h>
#include <string>
#include <regex>
#include "Manage_SQL_Queries.hpp"
#include "Client.hpp"
#include "SQL_Script_Names.hpp"

//! Definicion de la funcion createNewClient que permite crear un nuevo cliente en la base de datos
int createNewClient(sqlite3 *db, string nombre) {
    int data;
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(CREATE_NEW_CLIENT);
    query = regex_replace(query, regex("\\{0\\}"), nombre); 
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback_Create_New_Client, &data, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        return 0;
    }
    return data;
}

//! Definicion de la clase Client
Client::Client(int _id) : id(_id){}

//! Definicion del metodo que permite convertir el dinero en funcion del tipo de cambio
float Client::convertMoney(sqlite3 *db, string denominationSRC, string denominationDST, float quantity) {
    float data;
    char *errMsg = 0;
    int rc;
    string query;
    const char *sql;
    if (denominationSRC != denominationDST) {
        query = read_sql_file(CONVERT_MONEY);
        query = regex_replace(query, regex("\\{0\\}"), denominationSRC);
        query = regex_replace(query, regex("\\{1\\}"), denominationDST);
        query = regex_replace(query, regex("\\{2\\}"), to_string(quantity));
        sql = query.c_str();
        rc = sqlite3_exec(db, sql, callback_Convert_Money, &data, &errMsg);
        if (rc != SQLITE_OK) {
            cerr << "SQL error: " << errMsg << endl;
            sqlite3_free(errMsg);
            return 0;
        } else {
            quantity = data;
            return quantity;
        }
    }
    return quantity;
}

//! Definicion del metodo que permite depositar dinero en una cuenta
void Client::deposit(sqlite3 *db, string denominationSRC, string denominationDST, float quantity) {
    quantity = convertMoney(db, denominationSRC, denominationDST, quantity);
    char *errMsg = 0;
    int rc;
    string query;
    const char *sql;
    query = read_sql_file(DEPOSIT);
    query = regex_replace(query, regex("\\{0\\}"), to_string(id)); 
    query = regex_replace(query, regex("\\{1\\}"), denominationDST); 
    query = regex_replace(query, regex("\\{2\\}"), to_string(quantity)); 
    sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

//! Definicion del metodo que permite retirar dinero de una cuenta
void Client::retire(sqlite3 *db, string denominationSRC, string denominationDST, float quantity) {
    quantity = convertMoney(db, denominationSRC, denominationDST, quantity);
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(RETIRE);
    query = regex_replace(query, regex("\\{0\\}"), to_string(id)); 
    query = regex_replace(query, regex("\\{1\\}"), denominationDST); 
    query = regex_replace(query, regex("\\{2\\}"), to_string(quantity)); 
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}


