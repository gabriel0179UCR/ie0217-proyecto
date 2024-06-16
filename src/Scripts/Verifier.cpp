#include <iostream>
#include <string>
#include <sqlite3.h>
#include <regex>
#include "Verifier.hpp"
#include "Manage_SQL_Queries.hpp"
using namespace std;


Verifier::Verifier(int _id) : clientID(_id){}

bool Verifier::clientIdExist(sqlite3 *db) {
    int data;
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(".\\SQL_Scripts\\Verify_ClientID_Exist.sql");
    query = regex_replace(query, regex("\\{0\\}"), to_string(clientID)); 
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback_Verify_Money_Available, &data, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        if (data == 0)
            return false;
        return true;
    }
    return false;

}

bool Verifier::moneyAvailable(sqlite3 *db, string _denomination, float _quantity) {
    denomination = _denomination;
    quantity = _quantity;

    float data;
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(".\\SQL_Scripts\\Verify_Money_Available.sql");
    query = regex_replace(query, regex("\\{0\\}"), to_string(clientID)); 
    query = regex_replace(query, regex("\\{1\\}"), denomination);
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback_Verify_Money_Available, &data, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Operation done successfully" << endl;
        if (quantity > data) {
            return false;
        } else {
            return true;
        }
    }  
    return false;
};