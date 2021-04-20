#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;
NumberWithUnits::NumberWithUnits(double num, string name)
{
    _num = num;
    _name = name;
}
NumberWithUnits::NumberWithUnits(const NumberWithUnits &num)
{
    _num = num._num;
    _name = num._name;
}
void NumberWithUnits::read_units(std::ifstream &units_file)
{
}

NumberWithUnits NumberWithUnits::operator-() const
{
    NumberWithUnits tmp{-_num, _name};
    return tmp;
}
NumberWithUnits NumberWithUnits::operator+() const
{
    NumberWithUnits tmp{+_num, _name};
    return tmp;
}
NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &num) const
{
    NumberWithUnits tmp{_num + convert(num._num, num._name, _name), _name};
    return tmp;
}
NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &num) const
{
    NumberWithUnits tmp{_num - convert(num._num, num._name, _name), _name};
    return tmp;
}
NumberWithUnits operator*(const double x, const NumberWithUnits &num)
{
    NumberWithUnits tmp(num);
    tmp.setNumber(tmp.getNumber() * x);
    return tmp;
}
NumberWithUnits operator/(const double x, const NumberWithUnits &num)
{
    NumberWithUnits tmp(num);
    tmp.setNumber(tmp.getNumber() / x);
    return tmp;
}

NumberWithUnits &NumberWithUnits::operator--(int)
{
    this->_num -= 1;
    return *this;
}
NumberWithUnits &NumberWithUnits::operator++(int)
{
    this->_num += 1;
    return *this;
}
NumberWithUnits operator--(NumberWithUnits &num)
{
    NumberWithUnits tmp(num);
    tmp.setNumber(tmp.getNumber() - 1);
    num.setNumber(tmp.getNumber());
    return tmp;
}
NumberWithUnits operator++(NumberWithUnits &num)
{
    NumberWithUnits tmp(num);
    tmp.setNumber(tmp.getNumber() + 1);
    num.setNumber(tmp.getNumber());
    return tmp;
}

std::ostream &NumberWithUnits::operator<<(std::ostream &out)
{
    out << getNumber() << "[" << getName() << "]";
    return out;
}
std::istream &NumberWithUnits::operator>>(std::istream &in)
{
    double tmpNum = 0;
    in >> tmpNum;
    setNumber(tmpNum);
    string tmpStr;
    in >> tmpStr;
    if (!leagalName(tmpStr))
    {
        throw "name exception";
    }
    setName(tmpStr);
    return in;
}
ostream &operator<<(ostream &out, const NumberWithUnits &num)
{
    out << num.getNumber() << "[" << num.getName() << "]";
    return out;
}
istream &operator>>(istream &in, NumberWithUnits &num)
{
    double tmpNum = 0;
    in >> tmpNum;
    num.setNumber(tmpNum);
    string tmpStr;
    in >> tmpStr;
    if (!num.leagalName(tmpStr))
    {
        throw "name exception";
    }
    num.setName(tmpStr);
    return in;
}
