#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <sqlite3.h>
#include <string>
using namespace std;

class Client {
    private:
        int id;
    public:
        Client(int _id) : id(_id){}
        virtual ~Client(){} // Destructor
        void deposit(sqlite3 *db, string denominationID, int quantity);
        void retire(sqlite3 *db, string denominationID, int quantity);
};

#endif // CLIENT_HPP