#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <climits>


class Btc
{
    private:
        std::map<std::string, std::string> dataset;

    public:
        Btc(std::string data);
        Btc &operator=(Btc &copy);
        Btc(Btc &copy);
        ~Btc();
        void syntaxCheck(std::string line);
        void takeFile(std::string file);
        void loadDatabase(std::string data);
        void SearchDataSet(std::string date, std::string value);
};