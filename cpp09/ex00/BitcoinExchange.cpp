#include "BitcoinExchange.hpp"

Btc::Btc(char const *filename)
{
    _filename = filename;
    createMap();
}

Btc::~Btc() {}

void Btc::createMap()
{
    std::string line;

    std::ifstream data("data.csv");
    if (!data.is_open()) 
        throw std::runtime_error("Failed to open file: data.csv");
    std::getline(data, line);
    while (std::getline(data, line))
    {
        std::istringstream subs(line);
        std::string date;
        double rate;
        std::getline(subs, date, ',');
        subs >> rate;
        _data.insert(std::make_pair(date, rate));
    }
}

void Btc::find()
{
    std::ifstream input(_filename);
    if (!input.is_open()) 
        throw std::runtime_error("Failed to open file: " + std::string(_filename));
    
    std::string line;
    std::map<std::string, double>::iterator it;

    std::getline(input, line);
    while(std::getline(input, line)) 
    {
        std::istringstream ss(line);
        std::string date;
        double value;
        std::getline(ss, date, '|');
        date.erase(0, date.find_first_not_of(" \n\r\t"));
        date.erase(date.find_last_not_of(" \n\r\t") + 1);
        ss >> value;
        if (!checkDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        else {
            it = _data.find(date);
            if (it == _data.end()) {
                it = _data.upper_bound(date);
                if (it == _data.begin()) {
                    std::cerr << "Error: bad input => " << date << std::endl;
                    continue;
                }
                else
                    it--;
            } 
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number\n";
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number\n";
            continue;
        }
        double result = value * it->second;
        std::cout << it->first << " => " << value << " = " << result << std::endl;
    }
}

int Btc::checkDate(std::string date)
{
    std::istringstream str(date);
    int dt;
    std::getline(str, date, '-');
    str >> dt; 
    if (dt < 0)
        return 0;
    std::getline(str, date, '-');
    str >> dt; 
    if (dt > 12 || dt < 1)
        return (0);
    std::getline(str, date, '-');
    str >> dt; 
    if (dt > 31 || dt < 1)
        return (0);
    return (1);
}