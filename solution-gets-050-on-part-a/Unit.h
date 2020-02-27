#pragma once
#include <iostream>
using std::ostream, std::endl, std::string;

namespace ariel {
	enum class Unit {
		M, KM, CM,
		SEC, MIN, HOUR, 
		G, KG, TON
	};

	string unitToString(Unit u) {
		switch(u) {
			case Unit::M: return "m";
			case Unit::KM: return "km";
			case Unit::CM: return "km";
			case Unit::SEC: return "km";
			case Unit::MIN: return "km";
			case Unit::HOUR: return "km";
			case Unit::G: return "km";
			case Unit::KG: return "km";
			case Unit::TON: return "km";
		}
		return "hahaha";
	}

	inline ostream& operator<<(ostream& out, const Unit& u) {
	 	out << unitToString(u);
	 	return out;
	}
}

