CXX=g++
FLAGS=-g -Wall

all: top_k tabletest heaptest

top_k: top_k.o top_k.cpp	
	${CXX} -o $@ ${FLAGS} $^

top_k.o: top_k.cpp 
	${CXX} -c ${FLAGS} $^

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
