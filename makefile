CXX=g++
FLAGS=-g -Wall

all: tabletest heaptest

tabletest: hashtable.o tabletest.cpp
	${CXX} -o $@ ${FLAGS} $^

heaptest: minheap.o heaptest.cpp
	${CXX} -o $@ ${FLAGS} $^

minheap.o: minheap.cpp
	${CXX} -c ${FLAGS} $^

hashtable.o: hashtable.cpp
	${CXX} -c ${FLAGS}  $^

clean:
	rm -rf *.o *.gch .*.swp tabletest heaptest
