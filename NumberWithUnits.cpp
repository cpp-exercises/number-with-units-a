#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "NumberWithUnits.hpp"

using namespace std;
namespace ariel
{
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
    NumberWithUnits NumberWithUnits::operator--()
    {
        NumberWithUnits tmp(*this);
        tmp.setNumber(tmp.getNumber() - 1);
        setNumber(tmp.getNumber());
        return tmp;
    }
    NumberWithUnits NumberWithUnits::operator++()
    {
        NumberWithUnits tmp(*this);
        tmp.setNumber(tmp.getNumber() + 1);
        setNumber(tmp.getNumber());
        return tmp;
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
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &num) { return *this; }
    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &num) { return *this; }
    NumberWithUnits &NumberWithUnits::operator/=(const NumberWithUnits &num) { return *this; }
    NumberWithUnits &NumberWithUnits::operator*=(const NumberWithUnits &num) { return *this; }
    NumberWithUnits &NumberWithUnits::operator=(const NumberWithUnits &num) { return *this; }
    bool NumberWithUnits::operator<(const NumberWithUnits &num) const { return false; }
    bool NumberWithUnits::operator<=(const NumberWithUnits &num) const { return false; }
    bool NumberWithUnits::operator>(const NumberWithUnits &num) const { return false; }
    bool NumberWithUnits::operator>=(const NumberWithUnits &num) const { return false; }
    bool NumberWithUnits::operator==(const NumberWithUnits &num) const { return false; }
    bool NumberWithUnits::operator!=(const NumberWithUnits &num) const { return false; }

    double NumberWithUnits::convert(double num, std::string from, std::string to) { return 12; }
    std::string NumberWithUnits::getName() const
    {
        return this->_name;
    }
    double NumberWithUnits::getNumber() const
    {
        return this->_num;
    }
    bool NumberWithUnits::leagalName(const std::string &name) const
    {
        return true;
    }

};