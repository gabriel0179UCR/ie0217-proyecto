#include <iostream>
#include <sqlite3.h>
#include <string>
#include <regex>
#include "Manage_SQL_Queries.hpp"
#include "Client.hpp"

Client::Client(int _id) : id(_id){}

float Client::convertMoney(sqlite3 *db, string denominationSRC, string denominationDST, float quantity) {
    float data;
    char *errMsg = 0;
    int rc;
    string query;
    const char *sql;
    if (denominationSRC != denominationDST) {
        query = read_sql_file(".\\SQL_Scripts\\Buying_Money.sql");
        query = regex_replace(query, regex("\\{0\\}"), denominationSRC);
        query = regex_replace(query, regex("\\{1\\}"), denominationDST);
        query = regex_replace(query, regex("\\{2\\}"), to_string(quantity));
        sql = query.c_str();
        rc = sqlite3_exec(db, sql, callback_Buying_Money, &data, &errMsg);
        if (rc != SQLITE_OK) {
            cerr << "SQL error: " << errMsg << endl;
            sqlite3_free(errMsg);
            return 0;
        } else {
            cout << "Operation done successfully" << endl;
            quantity = data;
            cout << "Quantity: " << quantity << endl;
            return quantity;
        }
    }
    return quantity;
}

void Client::deposit(sqlite3 *db, string denominationSRC, string denominationDST, float quantity) {
    quantity = convertMoney(db, denominationSRC, denominationDST, quantity);
    char *errMsg = 0;
    int rc;
    string query;
    const char *sql;
    query = read_sql_file(".\\SQL_Scripts\\Deposit.sql");
    query = regex_replace(query, regex("\\{0\\}"), to_string(id)); 
    query = regex_replace(query, regex("\\{1\\}"), denominationDST); 
    query = regex_replace(query, regex("\\{2\\}"), to_string(quantity)); 
    sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Operation done successfully" << endl;
    }
}


void Client::retire(sqlite3 *db, string denominationSRC, string denominationDST, float quantity) {
    quantity = convertMoney(db, denominationSRC, denominationDST, quantity);
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(".\\SQL_Scripts\\Retire.sql");
    query = regex_replace(query, regex("\\{0\\}"), to_string(id)); 
    query = regex_replace(query, regex("\\{1\\}"), denominationDST); 
    query = regex_replace(query, regex("\\{2\\}"), to_string(quantity)); 
    cout << query << endl;
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Operation done successfully" << endl;
    }
}


