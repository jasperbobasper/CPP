#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class Btc
{
    public:
        Btc(char const *filename);
        ~Btc();
        void find();
    private:
        Btc();
        Btc( Btc const &cpy );
        Btc &operator=( Btc const &rhs);
        void createMap();
        int checkDate(std::string date);
        std::map<std::string, double> _data;
        char const *_filename;
};