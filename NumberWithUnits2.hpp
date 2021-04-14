#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
namespace ariel
{
    class NumberWithUnits
    {
    private:
        double amount;
        std::string kind;

    public:
        double &setAmount() { return this->amount; }
        double getAmount() const { return this->amount; }
        static std::map<std::string, std::map<std::string, double>> units;
        static void read_units(std::ifstream &file_name);
        NumberWithUnits(double amount, std::string kind) : amount(amount), kind(kind){};
        NumberWithUnits(const NumberWithUnits &other) : amount(other.amount), kind(other.kind){};
        NumberWithUnits &operator=(const NumberWithUnits &other);
        NumberWithUnits &operator+() { return *this; }
        const NumberWithUnits operator+(const NumberWithUnits &other) const;
        NumberWithUnits &operator+=(const NumberWithUnits &other);
        NumberWithUnits &operator-();
        const NumberWithUnits operator-(const NumberWithUnits &other) const;
        NumberWithUnits &operator-=(const NumberWithUnits &other);
        const NumberWithUnits operator++(int); //NumberWithUnits++
        NumberWithUnits &operator++();         // ++NumberWithUnits
        const NumberWithUnits operator--(int); //NumberWithUnits--
        NumberWithUnits &operator--();         // --NumberWithUnits

        bool operator<(const NumberWithUnits &other);
        bool operator<=(const NumberWithUnits &other);
        bool operator>(const NumberWithUnits &other);
        bool operator>=(const NumberWithUnits &other);
        bool operator==(const NumberWithUnits &other);
        bool operator!=(const NumberWithUnits &other);

        NumberWithUnits &operator*(double d);
        friend NumberWithUnits operator*(double d, const NumberWithUnits &n);
        friend std::ostream &operator<<(std::ostream &out, const NumberWithUnits &n);
        friend std::istream &operator>>(std::istream &in, const NumberWithUnits &n);
    };
};