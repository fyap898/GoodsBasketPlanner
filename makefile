CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
MODULES=main.o lib.o
TARGET=basket

$(TARGET): $(MODULES)
	g++ $(MODULES) $(GCOV_FLAGS) -o $(TARGET)

clean:
	rm -f *.o $(TEST) $(TARGET) *.*~ *.g* *.gcov* *.gcda* *.gcno*

all: clean $(TARGET)
	./$(TARGET)

main.o: main.cpp lib.h types.h
	g++ $(CPPFLAGS) $(GCOV_FLAGS) -c main.cpp

lib.o: lib.cpp lib.h types.h
	g++ $(CPPFLAGS) $(GCOV_FLAGS) -c lib.cpp

coverage: $(TARGET)
	./$(TARGET)
	gcov *.cpp
