/*
Execute commands

Compile: g++ create_empty_db.cpp -o create_empty_db -IC:\sqlite -LC:\sqlite -lsqlite3
Execute: .\create_empty_db.exe
*/

#include <iostream>
#include <sqlite3.h>
#include <fstream>
#include <string>
using namespace std;

string read_sql_file(const string& filename) {
  string content;
  try {
    ifstream file(filename);
    if (file.is_open()) {
      string line;
      while (getline(file, line)) {
        content += line + "\n";
      }
      file.close();
    } else {
      cerr << "Error: Could not open file '" << filename << "'" << endl;
    }
  } catch (const exception& e) {
    cerr << "Error: An exception occurred while reading the file: " << e.what() << endl;
  }
  return content;
}

static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    return 0;
}

int main(int argc, char* argv[]) {

    cout << "Initial" << endl;

    sqlite3 *db;
    char *errMsg = 0;
    int rc;
    const char* data = "Callback function called";

    rc = sqlite3_open("banco_ie0217_db.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return (0);
    } else {
        cout << "Opened database successfully" << endl;
    }

    string temp = read_sql_file(".\\SQL_Scripts\\Create_Empty_DB.sql");

    const char *sql = temp.c_str();
    rc = sqlite3_exec(db, sql, callback, (void*)data, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Operation done successfully" << endl;
    }
    cout << "End" << endl;
    sqlite3_close(db);
    return 0;
}