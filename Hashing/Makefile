#Name: Bailey Payne  ID: brp7vh  Lab: Tuesdays 9:30am

CXX = clang++
CXXFLAGS = -Wall -O2 -lrt 
OFILES = hashTable.o wordPuzzle.o timer.o

.SUFFIXES: .o .cpp

main:   $(OFILES)
	$(CXX) $(OFILES)

clean:
	/bin/rm -f *.o *~

#Dependencies:
hashTable.o: hashTable.cpp hashTable.h primenumber.cpp
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
timer.o: timer.cpp timer.h

