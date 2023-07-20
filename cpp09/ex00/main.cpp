#include "BitcoinExchange.hpp"
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        Btc bitcoin(argv[1]);
        bitcoin.find();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}