#include "minheap.h"

using namespace std;

int main(){
	MinHeap heap(20);

	heap.insert(1);
	heap.insert(2);
	heap.insert(3);
	heap.insert(4);
	heap.insert(5);
	heap.insert(6);
	heap.insert(7);
	heap.insert(8);

	heap.print();
}
