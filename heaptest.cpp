#include "minheap.h"
#include <iostream>

using namespace std;

int main(){
	MinHeap heap(20);

	pair<string, int> p("Daniel", 7);
	pair<string, int> q("Alex", 5);
	pair<string, int> r("Hello", 21);
	pair<string, int> s("Chumba", 13);
	pair<string, int> t("Wumba", 2);
	pair<string, int> u("Chatanooski", 10);
	pair<string, int> v("Benis", 4);
	pair<string, int> test("test", 1);

	heap.insert(p);
	heap.insert(q);
	heap.insert(r);
	heap.insert(s);
	heap.insert(t);
	heap.insert(u);
	heap.insert(v);
	heap.insert(test);

	heap.print();

	return 0;

}
