#pragma once
#include <iostream>
using std::ostream, std::istream;
#include "Unit.h"

namespace ariel {
	
	class PhysicalNumber {
		double myNum;
		Unit myUnit;
	public:
		PhysicalNumber(double num, Unit units) {
			myNum = num;
			myUnit = units;
		}
		friend ostream& operator<<(ostream& out, const PhysicalNumber& pn);
	};

	inline ostream& operator<<(ostream& out, const PhysicalNumber& pn) {
		out << pn.myNum << " [" << pn.myUnit << "]";
		return out;
	}

	inline istream& operator>>(istream& in, PhysicalNumber& pn) {
		return in;
	}

	inline PhysicalNumber operator+(const PhysicalNumber& a, const PhysicalNumber& b) {
		return a;
	}

	inline PhysicalNumber operator-(const PhysicalNumber& a, const PhysicalNumber& b) {
		return a;
	}

	inline PhysicalNumber& operator+=(PhysicalNumber& a, const PhysicalNumber& b) {
		return a;
	}

	inline PhysicalNumber& operator++(PhysicalNumber& a) {
		return a;
	}

	inline PhysicalNumber operator++(PhysicalNumber& a, int) {
		return a;
	}

	inline PhysicalNumber& operator--(PhysicalNumber& a) {
		return a;
	}

	inline PhysicalNumber operator--(PhysicalNumber& a, int) {
		return a;
	}

	inline PhysicalNumber& operator-=(PhysicalNumber& a, const PhysicalNumber& b) {
		return a;
	}

	inline PhysicalNumber operator+(const PhysicalNumber& a) {
		return a;
	}

	inline PhysicalNumber operator-(const PhysicalNumber& a) {
		return a;
	}

	inline bool operator>(const PhysicalNumber& a, const PhysicalNumber& b) {
		return true;
	}

	inline bool operator<(const PhysicalNumber& a, const PhysicalNumber& b) {
		return true;
	}

	inline bool operator>=(const PhysicalNumber& a, const PhysicalNumber& b) {
		return true;
	}

	inline bool operator<=(const PhysicalNumber& a, const PhysicalNumber& b) {
		return true;
	}

	inline bool operator==(const PhysicalNumber& a, const PhysicalNumber& b) {
		return true;
	}

	inline bool operator!=(const PhysicalNumber& a, const PhysicalNumber& b) {
		return true;
	}
}
