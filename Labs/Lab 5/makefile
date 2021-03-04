CXX = g++
CXXFLAGS = -Wall
lab5: Book.o lab5.cpp
		$(CXX) $(CXXFLAGS) Book.o lab5.cpp -o lab5
Book.o: Book.cpp Book.h
		$(CXX) $(CXXFLAGS) -c Book.cpp

run:
		./lab5