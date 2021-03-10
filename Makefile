CXX = g++
CFLAG = -Wall -Werror
CPPFLAGS = -MMD

all: ./bin/chessviz

./bin/chessviz:  ./obj/src/chessviz/main.o ./obj/src/libchessviz/libchessviz.a
	$(CXX) $(CFLAG)   obj/src/chessviz/main.o obj/src/libchessviz/libchessviz.a -o bin/chessviz

./obj/src/chessviz/main.o: src/chessviz/main.cpp
	$(CXX) $(CFLAG) $(CPPFLAGS)  -o obj/src/chessviz/main.o   -c  -I src/ src/chessviz/main.cpp

./obj/src/libchessviz/libchessviz.a: ./obj/src/libchessviz/mvpawn.o ./obj/src/libchessviz/checkmove.o
	ar rcs obj/src/libchessviz/libchessviz.a  obj/src/libchessviz/mvpawn.o obj/src/libchessviz/checkmove.o

./obj/src/libchessviz/checkmove.o: src/libchessviz/checkmove.cpp
	$(CXX) $(CFLAG) $(CPPFLAGS) -o obj/src/libchessviz/checkmove.o -c -I src/ src/libchessviz/checkmove.cpp

./obj/src/libchessviz/mvpawn.o: src/libchessviz/mvpawn.cpp
	$(CXX) $(CFLAG) $(CPPFLAGS) -o obj/src/libchessviz/mvpawn.o -c -I src/ src/libchessviz/mvpawn.cpp

-include obj/src/libchessviz/mvpawn.d obj/src/libchessviz/checkmove.d  obj/src/chessviz/main.d

.PHONY: clean
clean:
	rm ./bin/chessviz ./obj/src/libchessviz/*.o ./obj/src/chessviz/*.o
	rm ./obj/src/libchessviz/*.d ./obj/src/chessviz/*.d ./obj/src/libchessviz/libchessviz.a
