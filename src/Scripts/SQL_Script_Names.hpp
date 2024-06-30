#ifndef SQLSCRIPTNAMES_HPP
#define SQLSCRIPTNAMES_HPP

#include <string>
using namespace std;

//! Codigo de SQL que se encarga de crear un cliente nuevo en la base de datos
const string CREATE_NEW_CLIENT = ".\\SQL_Scripts\\Create_New_Client.sql";

//! Codigo de SQL que se encarga de solicitar informacion basica del cliente
const string GET_CLIENT_DATA = ".\\SQL_Scripts\\Get_Client_Data.sql";

//! Codigo de SQL que se encarga de convertir el dinero en funcion del tipo de cambio
const string CONVERT_MONEY = ".\\SQL_Scripts\\Convert_Money.sql";

//! Codigo de SQL que se encarga de depositar dinero en una cuenta
const string DEPOSIT = ".\\SQL_Scripts\\Deposit.sql";

//! Codigo de SQL que se encarga de retirar dinero de una cuenta
const string RETIRE = ".\\SQL_Scripts\\Retire.sql";

//! Codigo de SQL que se encarga de verificar si un ID de cliente existe en la base de datos
const string VERIFY_CLIENTID_EXIST = ".\\SQL_Scripts\\Verify_ClientID_Exist.sql";

//! Codigo de SQL que se encarga de verificar si se encuentra dinero disponible para retirar o transferir
const string VERIFY_MONEY_AVAILABLE = ".\\SQL_Scripts\\Verify_Money_Available.sql";

//! Codigo de SQL que se encarga de transferir dinero entre dos cuentas
const string TRANSFER = ".\\SQL_Scripts\\Transfer.sql";

//! Codigo de SQL que se encarga de consultar el reporte de transacciones
const string TRANSACTIONS = ".\\SQL_Scripts\\Transactions.sql";

//! Codigo de SQL que se encarga de consultar los tipos de prestamos
const string LOAN_INFO = ".\\SQL_Scripts\\Get_Loans_Types.sql";

//! Codigo de SQL que se encarga de crear prestamos para clientes
const string LOAN = ".\\SQL_Scripts\\Loan.sql";

//! Codigo de SQL que se encarga de abonar dinero en prestamos
const string LOAN_PAYMENT = ".\\SQL_Scripts\\Loan_Payment.sql";

//! Codigo de SQL que se encarga de consultar el interes de un tipo de prestamo
const string GET_INTEREST_LOAN = ".\\SQL_Scripts\\Get_Interest_Loan.sql";

//! Codigo de SQL que se encarga de crear CDPs
const string CDP = ".\\SQL_Scripts\\CDP.sql";

#endif // SQLSCRIPTNAMES_HPP