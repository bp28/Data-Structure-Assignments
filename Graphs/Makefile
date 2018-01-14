# Name: Bailey Payne  ID: brp7vh  Section: Tuesdays 9:30am

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2 -g
TFILES = traveling.o
MFILES = middleearth.o

.SUFFIXES: .o .cpp

output: $(TFILES) $(MFILES)
	$(CXX) $(TFILES) $(MFILES)
	doxygen

clean:
	/bin/rm -f *.o *~

