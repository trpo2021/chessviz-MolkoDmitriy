CC = g++
CFLAG = -Wall -Werror


main: src/chessviz/main.cpp
	$(CC) $(CFLAG)  -o main src/chessviz/main.cpp
