CC = g++
CFLAG = -Wall -Werror

all: chessviz

chessviz: ./obj/src/libchessviz/mvpawn.o ./obj/src/libchessviz/checkmove.o ./obj/src/libchessviz/main.o
	$(CC) obj/src/libchessviz/mvpawn.o obj/src/libchessviz/checkmove.o obj/src/libchessviz/main.o -o bin/chessviz

./obj/src/libchessviz/main.o: src/chessviz/main.cpp
	$(CC) $(CFLAG)  -o obj/src/libchessviz/main.o   -c src/chessviz/main.cpp


./obj/src/libchessviz/checkmove.o: src/libchessviz/checkmove.cpp
	$(CC) $(CFLAG)  -o obj/src/libchessviz/checkmove.o -c src/libchessviz/checkmove.cpp

./obj/src/libchessviz/mvpawn.o: src/libchessviz/mvpawn.cpp
	$(CC) $(CFLAG) -o obj/src/libchessviz/mvpawn.o -c src/libchessviz/mvpawn.cpp

.PHONY: clean
clean:
	rm /bin/chessviz /obj/src/libchessviz/*.o
