CXX = g++
CXXFLAGS = -Wall

lab6: lab6.cpp Candy.o
		$(CXX) $(CXXFLAGS) lab6.cpp Candy.o -o lab6
Candy.o: Candy.h Candy.cpp
		$(CXX) $(CXXFLAGS) -c Candy.cpp

run:
		./lab6


clean:
		rm *~