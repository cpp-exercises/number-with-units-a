#include <fstream>
#include <string>
#include <iostream>

namespace ariel
{
    class NumberWithUnits
    {
        double _num;
        std::string _name;

    public:
        NumberWithUnits(double num, std::string name);
        void read_units(std::ifstream units_file);
        NumberWithUnits operator-();
        friend std::ostream operator<<(std::ostream in,NumberWithUnits& num);
        bool operator>(NumberWithUnits& num);
    };
}