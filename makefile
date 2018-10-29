CXX=g++
FLAGS=-g -Wall

tabletest: hashtable.o tabletest.cpp
	${CXX} -o $@ ${FLAGS} $^

minheaptest: minheap.o minheaptest.cpp
	${CXX} -o $@ ${FLAGS} $^

minheap.o: minheap.cpp
	${CXX} -c ${FLAGS} $^

hashtable.o: hashtable.cpp
	${CXX} -c ${FLAGS}  $^

clean:
	rm -rf *.o *.gch .*.swp tabletest
