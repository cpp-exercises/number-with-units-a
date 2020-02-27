#!make -f

all: demo
	./$<

demo:  PhysicalNumber.o OurPhysicalNumberDemo.o
	clang++-5.0 -std=c++17 $^ -o demo

test:  PhysicalNumber.o OurPhysicalNumberTest.o 
	clang++-5.0 -std=c++17 $^ -o test

your_test_our_class: PhysicalNumberTest.cpp
	clang++-5.0 -std=c++17 PhysicalNumberTest.cpp -o your_test_our_class

%.o: %.cpp
	clang++-5.0 -std=c++17 --compile $< -o $@

%PhysicalNumber%.o: PhysicalNumber.h Unit.h
%Test%.o: badkan.hpp

clean:
	rm -f *.o demo test your_test_our_class
