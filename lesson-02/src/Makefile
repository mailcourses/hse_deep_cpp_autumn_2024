
CC=g++
FLAGS=-std=c++20 -Wall -Wextra -Werror

test_bin: vector.o test.o
	$(CC) $(FLAGS) vector.o test.o -o test_bin -lgtest_main -lgtest -lpthread

test.o: test.cpp vector.hpp
	$(CC) $(FLAGS) -c test.cpp -lgtest_main -lgtest -lpthread

vector.o: vector.hpp vector.cpp
	$(CC) $(FLAGS) -c vector.cpp

test:
	./test_bin

clean:
	rm -f *.o test_bin
