#include "Manage_SQL_Queries.hpp"

#include <iostream>
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
    cerr << "Error: General: " << e.what() << endl;
  }
  return content;
}

int callback(void *data, int argc, char **argv, char **azColName) {
  for (int i = 0; i < argc; i++) {
      cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
  }
  return 0;
}