CXX = g++
CXXFLAGS = -Wall

proj4: AgItem.o Fruit.o Vegetable.o Tree.o Animal.o Farm.o proj4.cpp
	$(CXX) $(CXXFLAGS) AgItem.o Fruit.o Vegetable.o Tree.o Animal.o Farm.o proj4.cpp -o proj4

Farm.o: AgItem.o Vegetable.o Tree.o Animal.o Farm.cpp Farm.h
		$(CXX) $(CXXFLAGS) -c Farm.cpp

Animal.o: AgItem.o Animal.cpp Animal.h
		$(CXX) $(CXXFLAGS) -c Animal.cpp

Tree.o: AgItem.o Fruit.o Tree.cpp Tree.h
		$(CXX) $(CXXFLAGS) -c Tree.cpp

Vegetable.o: AgItem.o Vegetable.cpp Vegetable.h
		$(CXX) $(CXXFLAGS) -c Vegetable.cpp

Fruit.o: Fruit.cpp Fruit.h
		$(CXX) $(CXXFLAGS) -c Fruit.cpp

AgItem.o: AgItem.cpp AgItem.h
		$(CXX) $(CXXFLAGS) -c AgItem.cpp

clean:
	rm *.o*
	rm *~ 