#include <iostream>
#include <sqlite3.h>
#include <fstream>
#include <string>
#include <regex>
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

void createNewClient(sqlite3 *db) {
    const char* data = "Callback function called";
    char *errMsg = 0;
    int rc;
    string query = read_sql_file(".\\SQL_Scripts\\Create_New_Client.sql");
    query = regex_replace(query, regex("\\{0\\}"), "test"); 
    const char *sql = query.c_str();
    rc = sqlite3_exec(db, sql, callback, (void*)data, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Operation done successfully" << endl;
    }
}

//int main(int argc, char* argv[]) {
//
//    sqlite3 *db;
//    int rc;
//    rc = sqlite3_open("banco_ie0217_db.db", &db);
//    createNewClient(db);
//
//    sqlite3_close(db);
//    return 0;
//}