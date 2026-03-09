EXEC= tp8
CXXFLAGS= -g -O0 -Wall -std=c++17

$(EXEC) : animal.o attaque.o main.o
	g++ -o $(EXEC) animal.o attaque.o main.o

main.o : main.cpp attaque.h animal.h
	g++ -c $(CXXFLAGS) main.cpp

animal.o : animal.cpp animal.h
	g++ -c $(CXXFLAGS) animal.cpp

attaque.o : attaque.cpp attaque.h
	g++ -c $(CXXFLAGS) attaque.cpp

clean :
	rm -f $(EXEC) *.o