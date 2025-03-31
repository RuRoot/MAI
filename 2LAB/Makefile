all: main.o funcs.o
	g++ main.o funcs.o
main.o: main.cpp
	g++ -c main.cpp
funcs.o: funcs.cpp
	g++ -c funcs.cpp
clean:
	rm -rf *.out *.o
