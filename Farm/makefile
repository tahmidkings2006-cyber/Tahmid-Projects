CXX = g++
CXXFLAGS = -Wall -g

proj4: proj4.cpp Farm.o AgItem.o Animal.o Vegetable.o Tree.o Fruit.o
	$(CXX) $(CXXFLAGS) proj4.cpp Farm.o AgItem.o Animal.o Vegetable.o Tree.o Fruit.o -o proj4

Farm.o: Farm.h Farm.cpp AgItem.h Animal.h Vegetable.h Tree.h
	$(CXX) $(CXXFLAGS) -c Farm.cpp

AgItem.o: AgItem.h AgItem.cpp
	$(CXX) $(CXXFLAGS) -c AgItem.cpp

Animal.o: Animal.h Animal.cpp AgItem.h
	$(CXX) $(CXXFLAGS) -c Animal.cpp

Vegetable.o: Vegetable.h Vegetable.cpp AgItem.h
	$(CXX) $(CXXFLAGS) -c Vegetable.cpp

Tree.o: Tree.h Tree.cpp AgItem.h Fruit.h
	$(CXX) $(CXXFLAGS) -c Tree.cpp

Fruit.o: Fruit.h Fruit.cpp
	$(CXX) $(CXXFLAGS) -c Fruit.cpp

run:
	./proj4

clean:
	rm -f *~ *.o proj4

val:
	valgrind ./proj4

