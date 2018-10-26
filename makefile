CXX=g++
FLAGS=-g -Wall
tabletest: hashtable.o tabletest.cpp
	${CXX} -o test ${FLAGS} $^

hashtable.o: hashtable.cpp
	${CXX} -c ${FLAGS}  $^

clean:
	rm -rf *.o *.gch .*.swp