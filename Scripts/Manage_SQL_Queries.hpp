#ifndef MANAGESQLQUERIES_HPP
#define MANAGESQLQUERIES_HPP

#include <string>
using namespace std;

string read_sql_file(const string& filename);
int callback(void *data, int argc, char **argv, char **azColName);

#endif