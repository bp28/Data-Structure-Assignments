#Name: Bailey Payne  ID: brp7vh  Lab: Tuesdays 9:30am

CXX = clang++
CXXFLAGS = -Wall -O2
OFILES = huffmandec.o huffman_node.o

.SUFFIXES: .o .cpp

main:   $(OFILES)
	$(CXX) $(OFILES)

clean:
	/bin/rm -f *.o *~

#Dependencies:
huffmandec.o: huffmandec.cpp huffman_node.h
huffman_node.o: huffman_node.cpp huffman_node.h

