#include "minheap.h"

using namespace std;

int main(){
	MinHeap heap(20);

	for (int i = 5 ; i < 0; i++){
		heap.insert(i);
		heap.print();
	}

	return 0;

}
