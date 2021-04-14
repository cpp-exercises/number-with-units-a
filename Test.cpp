#include "NumberWithUnits.hpp"
#include "doctest.h"
#include <iostream>

using namespace std;
using namespace ariel;

TEST_CASE("good cases")
{
    NumberWithUnits x(0, "km");
    CHECK(x.getNumber() == 0);
    CHECK(x.getName() == "km");
    x.setNumber(12);
    CHECK(x.getNumber() == 12);
    x.setNumber(-12);
    CHECK(x.getNumber() == -12);
    x.setName("cm");
    CHECK(x.getName() == "cm");
    CHECK((-x).getName() == "cm");
    CHECK((-x).getNumber() == 12);
    NumberWithUnits y(0, "km");
    CHECK((x + y).getName() == "cm");
    CHECK((x + y).getNumber() == -120000);
    CHECK((-1 * x).getNumber() == 12);
    x.setName("cm");
    y.setNumber(13);
    x += y;
    CHECK(x.getNumber() == 1);
    x -= y;
    CHECK(x.getNumber() == -12);
    CHECK(x < y);
    CHECK(x != y);
    x.setNumber(13);
    CHECK(x == y);
    x += y;
    CHECK(x > y);
    x--;
    CHECK(x.getNumber() == 22);
    x++;
    CHECK(x.getNumber() == 23);
    --x;
    CHECK(x.getNumber() == 22);
    ++x;
    CHECK(x.getNumber() == 23);
}
TEST_CASE("bad cases")
{
    CHECK_THROWS(NumberWithUnits x(0, "fff"));
    NumberWithUnits x(0, "km");
    NumberWithUnits y(0, "sec");

    CHECK_THROWS(x.setName("fff"));
    CHECK_THROWS(x + y);
    CHECK_THROWS(x - y);
}
