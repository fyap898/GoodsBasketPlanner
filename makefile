CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
MODULES=main.o lib.o
TARGET=basket

$(TARGET): $(MODULES)
	g++ $(MODULES) $(GCOVFLAGS) -o $(TARGET)

clean:
	/bin/rm -f *.o $(TEST) $(TARGET) *.*~ *.g*

all: clean $(TARGET)
	./$(TARGET)

main.o: main.cpp lib.h types.h
	g++ $(CPPFLAGS) -c main.cpp

lib.o: lib.cpp lib.h types.h
	g++ $(CPPFLAGS) -c lib.cpp

