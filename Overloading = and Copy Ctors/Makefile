run: all
	./bin/example

all: dir example

example: main.o Person.o
	g++ -o ./bin/example ./bin/main.o ./bin/Person.o

main.o: main.cpp
	g++ -c main.cpp -o ./bin/main.o

Person.o: Person.cpp
	g++ -c Person.cpp -o ./bin/Person.o

dir:
	mkdir -p bin

clean:
	rm -f ./bin/*
	#rm -f *.o example
