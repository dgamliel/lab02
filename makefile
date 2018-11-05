CXX=g++
FLAGS=-g -Wall

all: top_k tabletest heaptest

top_k: minheap.o hashtable.o top_k.o main.cpp	
	${CXX} -o $@ ${FLAGS} $^

top_k.o: minheap.o hashtable.o top_k.cpp 
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
	rm -rf *.o *.gch .*.swp tabletest heaptest main top_k
