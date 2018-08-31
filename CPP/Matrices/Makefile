CXX = g++
EXECUTABLE = output
OBJECTS = main.o matrices.o

$(EXECUTABLE): $(OBJECTS)
	$(CXX) main.o matrices.o -o $(EXECUTABLE)

main.o: main.cpp matrices.h 
	$(CXX) -c main.cpp

matrices.o: matrices.cpp matrices.h
	$(CXX) -c matrices.cpp

clean: 
	rm *.o $(EXECUTABLE) 
