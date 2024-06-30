#include <iostream>
#include <sqlite3.h>
#include <string>
#include <regex>
#include <math.h>
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
Client::Client(int _id, sqlite3 *_db) : id(_id),db(_db){
    char *errMsg = 0;
    int rc;
    string query;
    const char *sql;
    query = read_sql_file(GET_CLIENT_DATA);
    query = regex_replace(query, regex("\\{0\\}"), to_string(id)); 
    sql = query.c_str();
    cout << endl << "Informacion general del cliente" << endl;
    rc = sqlite3_exec(db, sql, callback_Get_Client_Data, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

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
    rc = sqlite3_exec(db, sql, callback_Deposit, 0, &errMsg);
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
    rc = sqlite3_exec(db, sql, callback_Retire, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}


//! Definicion del metodo que permite transferir dinero entre cuentas
void Client::transfer(sqlite3 *db, string denominationSRC, int idDST, string denominationDST, string denominationQuantity, float quantity){
    float quantitySRC;
    float quantityDST;

    if (denominationSRC == denominationQuantity && denominationDST == denominationQuantity) {
        quantitySRC = quantity;
        quantityDST = quantity;
    } else if (denominationSRC == denominationQuantity && denominationDST != denominationQuantity) {
        quantitySRC = quantity;
        quantityDST = convertMoney(db, denominationQuantity, denominationDST, quantity);
    } else if (denominationSRC != denominationQuantity && denominationDST == denominationQuantity) {
        quantitySRC = convertMoney(db, denominationQuantity, denominationSRC, quantity);
        quantityDST = quantity;
    } else {
        quantitySRC = convertMoney(db, denominationQuantity, denominationSRC, quantity);
        quantityDST = convertMoney(db, denominationQuantity, denominationDST, quantity);
    }
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(TRANSFER);
    query = regex_replace(query, regex("\\{0\\}"), to_string(id)); 
    query = regex_replace(query, regex("\\{1\\}"), to_string(idDST)); 
    query = regex_replace(query, regex("\\{2\\}"), to_string(quantitySRC));
    query = regex_replace(query, regex("\\{3\\}"), to_string(quantityDST)); 
    query = regex_replace(query, regex("\\{4\\}"), denominationSRC); 
    query = regex_replace(query, regex("\\{5\\}"), denominationDST); 
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback_Transfer, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

//! Definicion del metodo que consulta el registro de transacciones
void Client::transactions(sqlite3 *db) {
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(TRANSACTIONS);
    query = regex_replace(query, regex("\\{0\\}"), to_string(id)); 
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback_Transactions, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

//! Definicion del metodo que crea prestamos a clientes
void Client::loan(sqlite3 *db, string loanType, string denomination, float quantity, int fee) {
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(LOAN);
    query = regex_replace(query, regex("\\{0\\}"), to_string(id));
    query = regex_replace(query, regex("\\{1\\}"), loanType); 
    query = regex_replace(query, regex("\\{2\\}"), denomination); 
    query = regex_replace(query, regex("\\{3\\}"), to_string(quantity));
    query = regex_replace(query, regex("\\{4\\}"), to_string(fee));
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback_Loan, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } 

    float interest = getInterest(db, loanType);
    float totalPayment = 0;
    cout << endl << "Tabla de pagos" << endl;
    cout << endl << "Monto" << "| Numero de cuota |" << "Interes" << endl;
    for (int i=0; i<fee*12; i++) {
        totalPayment = totalPayment + (1+interest/100)*quantity/(fee*12);
        cout << to_string(std::round(totalPayment*100.0f)/100.0f) << " | " << i+1 << " | " << interest << endl;
    }
};

//! Definicion del metodo que abona dinero a un prestamo
void Client::loan_payment(sqlite3 *db, int loanID, string denominationDST, string denominationQuantity, float quantity) {
    quantity = convertMoney(db, denominationQuantity, denominationDST, quantity);
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(LOAN_PAYMENT);
    query = regex_replace(query, regex("\\{0\\}"), to_string(loanID));
    query = regex_replace(query, regex("\\{1\\}"), to_string(quantity)); 
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback_Loan_Payment, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } 
};

//! Definicion de la funcion que consulta la informacion de prestamos
void getLoansTypes(sqlite3 *db) {
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(LOAN_INFO);
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback_Get_Loans_Types, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } 
};

//! Definicion de la funcion que consulta el interes de un tipo de prestamo
float getInterest(sqlite3 *db, string loanType) {
    float data;
    char *errMsg = 0;
    int rc;
    string query;
    const char *sql;
    query = read_sql_file(GET_INTEREST_LOAN);
    query = regex_replace(query, regex("\\{0\\}"), loanType);
    sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback_Get_Interest_Loan, &data, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        return 0;
    } else {
        return data;
    }
};