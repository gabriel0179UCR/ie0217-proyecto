#include <iostream>
#include <sqlite3.h>
#include <string>
#include <regex>
#include "Manage_SQL_Queries.hpp"
#include "Client.hpp"

Client::Client(int _id) : id(_id){}


void Client::deposit(sqlite3 *db, string denominationID, int quantity) {
    const char* data = "Callback function called";
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(".\\SQL_Scripts\\Deposit.sql");
    query = regex_replace(query, regex("\\{0\\}"), to_string(id)); 
    query = regex_replace(query, regex("\\{1\\}"), denominationID); 
    query = regex_replace(query, regex("\\{2\\}"), to_string(quantity)); 
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback, (void*)data, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Operation done successfully" << endl;
    }
}


void Client::retire(sqlite3 *db, string denominationID, int quantity) {
    const char* data = "Callback function called";
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(".\\SQL_Scripts\\Retire.sql");
    query = regex_replace(query, regex("\\{0\\}"), to_string(id)); 
    query = regex_replace(query, regex("\\{1\\}"), denominationID); 
    query = regex_replace(query, regex("\\{2\\}"), to_string(quantity)); 
    cout << query << endl;
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback, (void*)data, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Operation done successfully" << endl;
    }
}


