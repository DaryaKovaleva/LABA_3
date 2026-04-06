CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = lab3.exe
SOURCES = main.cpp TestsDynamicArray.cpp TestsLinkedList.cpp TestsArraySequence.cpp TestsListSequence.cpp TestsImmutableArraySequence.cpp TestsNew.cpp TestsMain.cpp
OBJECTS = main.o TestsDynamicArray.o TestsLinkedList.o TestsArraySequence.o TestsListSequence.o TestsImmutableArraySequence.o TestsNew.o TestsMain.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cpp DynamicArray.h LinkedList.h Sequence.h ArraySequence.h ListSequence.h ImmutableArraySequence.h Queue.h Stack.h Deque.h Matrix.h Tests.h
	$(CXX) $(CXXFLAGS) -c main.cpp

TestsDynamicArray.o: TestsDynamicArray.cpp Tests.h DynamicArray.h
	$(CXX) $(CXXFLAGS) -c TestsDynamicArray.cpp

TestsLinkedList.o: TestsLinkedList.cpp Tests.h LinkedList.h
	$(CXX) $(CXXFLAGS) -c TestsLinkedList.cpp

TestsArraySequence.o: TestsArraySequence.cpp Tests.h ArraySequence.h Sequence.h
	$(CXX) $(CXXFLAGS) -c TestsArraySequence.cpp

TestsListSequence.o: TestsListSequence.cpp Tests.h ListSequence.h Sequence.h
	$(CXX) $(CXXFLAGS) -c TestsListSequence.cpp

TestsImmutableArraySequence.o: TestsImmutableArraySequence.cpp Tests.h ImmutableArraySequence.h ArraySequence.h Sequence.h
	$(CXX) $(CXXFLAGS) -c TestsImmutableArraySequence.cpp

TestsNew.o: TestsNew.cpp Tests.h Queue.h Stack.h Deque.h Matrix.h
	$(CXX) $(CXXFLAGS) -c TestsNew.cpp

TestsMain.o: TestsMain.cpp Tests.h DynamicArray.h LinkedList.h ArraySequence.h ListSequence.h ImmutableArraySequence.h Queue.h Stack.h Deque.h Matrix.h
	$(CXX) $(CXXFLAGS) -c TestsMain.cpp

clean:
	del *.o $(TARGET).exe

run: $(TARGET)
	$(TARGET)

.PHONY: all clean run