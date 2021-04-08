CXX = g++
CFLAG = -Wall -Werror
CPPFLAGS = -MMD
PLibobj = ./obj/src/libchessviz
PSrcobj = ./obj/src/chessviz
PLib = ./src/libchessviz
PSrc = ./src/chessviz

all: ./bin/chessviz
.PHONY: test
test: ./bin/chessviz-tests

./bin/chessviz-tests: ./obj/test/main.o $(PLibobj)/libchessviz.a
	$(CXX) $(CFLAG) ./obj/test/main.o	$(PLibobj)/libchessviz.a -o ./bin/chessviz-tests

./obj/test/main.o: ./test/main.cpp
	$(CXX) $(CFLAG) $(CPPFLAGS) -o ./obj/test/main.o -c -I src/ ./test/main.cpp

./bin/chessviz:  $(PSrcobj)/main.o $(PLibobj)/libchessviz.a
	$(CXX) $(CFLAG)   $(PSrcobj)/main.o $(PLibobj)/libchessviz.a -o ./bin/chessviz

$(PSrcobj)/main.o: $(PSrc)/main.cpp
	$(CXX) $(CFLAG) $(CPPFLAGS)  -o $(PSrcobj)/main.o   -c  -I src/ $(PSrc)/main.cpp

$(PLibobj)/libchessviz.a: $(PLibobj)/mvpawn.o $(PLibobj)/checkmove.o $(PLibobj)/convert_to_int.o $(PLibobj)/mvfigure.o
	ar rcs $(PLibobj)/libchessviz.a  $(PLibobj)/mvpawn.o $(PLibobj)/checkmove.o $(PLibobj)/convert_to_int.o $(PLibobj)/mvfigure.o

$(PLibobj)/checkmove.o: $(PLib)/checkmove.cpp
	$(CXX) $(CFLAG) $(CPPFLAGS) -o $(PLibobj)/checkmove.o -c -I src/ $(PLib)/checkmove.cpp

$(PLibobj)/mvpawn.o: $(PLib)/mvpawn.cpp
	$(CXX) $(CFLAG) $(CPPFLAGS) -o $(PLibobj)/mvpawn.o -c -I src/ $(PLib)/mvpawn.cpp

$(PLibobj)/convert_to_int.o: $(PLib)/convert_to_int.cpp
	$(CXX) $(CFLAG) $(CPPFLAGS) -o $(PLibobj)/convert_to_int.o -c -I src/  $(PLib)/convert_to_int.cpp

$(PLibobj)/mvfigure.o: $(PLib)/mvfigure.cpp
	$(CXX) $(CFLAG) $(CPPFLAGS) -o $(PLibobj)/mvfigure.o -c -I src/  $(PLib)/mvfigure.cpp

-include $(PLibobj)/mvpawn.d $(PLibobj)/checkmove.d $(PSrcobj)/main.d  $(PLibobj)/convert_to_int.d $(PLibobj)/mvfigure.d  ./obj/test/main.d

.PHONY: clean
clean:
	rm ./bin/chessviz $(PLibobj)/*.o $(PSrcobj)/*.o
	rm $(PLibobj)/*.d $(PSrcobj)/*.d $(PLibobj)/libchessviz.a ./obj/test/main.d ./obj/test/main.o
