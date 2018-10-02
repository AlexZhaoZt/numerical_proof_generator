CXXFLAGS = -std=c++11 -g -O0 -Wall -Wextra

finder : main.o
	clang++ $(CXXFLAGS) main.o -o finder
main.o : main.cpp main.h
	clang++ $(CXXFLAGS) -c main.cpp

clean :
	rm finder
