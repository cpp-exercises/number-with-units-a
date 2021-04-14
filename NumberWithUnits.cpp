#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;
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
std::ostream &operator<<(std::ostream &out, const NumberWithUnits &num)
{
    out << num.getNumber() << "[" << num.getName() << "]";
    return out;
}
std::istream &operator>>(std::istream &in, NumberWithUnits &num)
{
    double tmpNum;
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
