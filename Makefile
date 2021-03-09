CXX = g++
CFLAG = -Wall -Werror

all: ./bin/chessviz

./bin/chessviz: ./obj/src/libchessviz/mvpawn.o ./obj/src/libchessviz/checkmove.o ./obj/src/libchessviz/main.o
	$(CXX) obj/src/libchessviz/mvpawn.o obj/src/libchessviz/checkmove.o obj/src/chessviz/main.o  -o bin/chessviz

./obj/src/libchessviz/main.o: src/chessviz/main.cpp
	$(CXX) $(CFLAG)  -o obj/src/chessviz/main.o   -c  -I src/ src/chessviz/main.cpp


./obj/src/libchessviz/checkmove.o: src/libchessviz/checkmove.cpp
	$(CXX) $(CFLAG)  -o obj/src/libchessviz/checkmove.o -c -I src/ src/libchessviz/checkmove.cpp

./obj/src/libchessviz/mvpawn.o: src/libchessviz/mvpawn.cpp
	$(CXX) $(CFLAG) -o obj/src/libchessviz/mvpawn.o -c -I src/ src/libchessviz/mvpawn.cpp

.PHONY: clean
clean:
	rm ./bin/chessviz ./obj/src/libchessviz/*.o
