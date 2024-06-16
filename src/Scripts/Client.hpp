#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <sqlite3.h>
#include <string>
using namespace std;

class Client {
    private:
        int id;
    public:
        Client(int _id);
        virtual ~Client(){} // Destructor
        void deposit(sqlite3 *db, string denominationSRC, string denominationDST, float quantity);
        void retire(sqlite3 *db, string denominationSRC, string denominationDST, float quantity);
        float convertMoney(sqlite3 *db, string denominationSRC, string denominationDST, float quantity);
};

#endif // CLIENT_HPP