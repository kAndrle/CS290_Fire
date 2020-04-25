CXX = g++
CXXFLAGS = -Wall -g

main: main.o menu.o forest.o
	$(CXX) $(CXXFLAGS) -o main main.o menu.o forest.o
	
main.o: main.cpp menu.h forest.h
	$(CXX) $(CXXFLAGS) -c main.cpp
	
menu.o: menu.h
forest.o: forest.h

clean:
	-rm main.exe main.o menu.o forest.o
	
cleanExecutable:
	-rm main.exe
	
cleanObjects:
	-rm main.o menu.o forest.o