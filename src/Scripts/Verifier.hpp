#ifndef VERIFIER_HPP
#define VERIFIER_HPP

#include <string>
#include <sqlite3.h>
using namespace std;

class Verifier{
    private:
        int id;
        float quantity;
        string denomination;
        bool allow;
    public:
        Verifier(int _id);
        virtual ~Verifier(){} // Destructor
        bool moneyAvailable(sqlite3 *db, string _denomination, float _quantity);
};

#endif // VERIFIER_HPP