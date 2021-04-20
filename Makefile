#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a -Werror -Wsign-conversion

SOURCES=NumberWithUnits.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

run: demo
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# your_test_our_class: NumberWithUnitsTest.cpp
# 	$(CXX) $(CXXFLAGS) NumberWithUnitsTest.cpp -o your_test_our_class

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@


clean:
	rm -f *.o demo test
