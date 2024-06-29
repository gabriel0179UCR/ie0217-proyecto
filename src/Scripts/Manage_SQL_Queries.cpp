#include "Manage_SQL_Queries.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "Verifier.hpp"
using namespace std;

//! Definicion de la funcion que permite almacenar el codigo de SQL en un string
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

//! Definicion de la funcion callback para la ejecucion de codigo de SQL general
int callback(void *data, int argc, char **argv, char **azColName) {
  //for (int i = 0; i < argc; i++) {
  //    cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
  //}
  return 0;
}

//! Definicion de la funcion callback que muestra la informacion general del cliente
int callback_Get_Client_Data(void *data, int argc, char **argv, char **azColName) {
  for (int i = 0; i < argc; i=i+6) {
    for (int j = 0; j < 6; j++) {
      cout << azColName[i+j] << " = " << (argv[i+j] ? argv[i+j] : "NULL") << " | ";
    }
    cout << endl;
  }
  return 0;
}

//! Definicion de la funcion callback para la ejecucion de codigo de SQL que verifica si hay dinero disponible en la cuenta
int callback_Verify_Money_Available(void *data, int argc, char **argv, char **azColName) {
  float* result = static_cast<float *>(data);
  *result = stof(argv[0]);
  return 0;
}

//! Definicion de la funcion callback para la ejecucion de codigo de SQL que verifica si existe el ID del cliente ingresado
int callback_Verify_ClientID_Exist(void *data, int argc, char **argv, char **azColName) {
  int* result = static_cast<int *>(data);
  *result = stoi(argv[0]);
  return 0;
}

//! Definicion de la funcion callback para la ejecucion de codigo de SQL que convierte el dinero segun el tipo de cambio
int callback_Convert_Money(void *data, int argc, char **argv, char **azColName) {
  float* result = static_cast<float *>(data);
  *result = stof(argv[0]);
  return 0;
}

//! Definicion de la funcion callback para la ejecucion de codigo de SQL que crea un nuevo cliente en la base de datos
int callback_Create_New_Client(void *data, int argc, char **argv, char **azColName) {
  int* result = static_cast<int *>(data);
  *result = stoi(argv[0]);
  return 0;
}

//! Definicion de la funcion callback para el metodo que deposita dinero en una cuenta
int callback_Deposit(void *data, int argc, char **argv, char **azColName) {
  cout << endl << "Deposito realizado correctamente" << endl;
  for (int i = 0; i < argc; i++) {
      cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << " | ";
  }
  cout << endl;

  return 0;
};

//! Definicion de la funcion callback para el metodo que retira dinero en una cuenta
int callback_Retire(void *data, int argc, char **argv, char **azColName) {
  cout << endl << "Retiro realizado correctamente" << endl;
  for (int i = 0; i < argc; i++) {
      cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << " | ";
  }
  cout << endl;

  return 0;
};

//! Definicion de la funcion callback para el metodo que transfiere dinero de una cuenta a otra
int callback_Transfer(void *data, int argc, char **argv, char **azColName) {
  cout << endl << "Transferencia realizada correctamente" << endl;
  for (int i = 0; i < argc; i++) {
      cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << " | ";
  }
  cout << endl;

  return 0;
};