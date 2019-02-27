run: all
	./example

all: example

example: main.o Person.o
	g++ -o example main.o Person.o

main.o: main.cpp
	g++ -c main.cpp

Person.o: Person.cpp
	g++ -c Person.cpp

clean:
	rm -f *.o example
