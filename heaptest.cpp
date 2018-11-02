#include "minheap.h"
#include <iostream>

using namespace std;

int main(){
	MinHeap heap(20);

	for (int i = 5 ; i > 0; i--){
		heap.insert(i);
		heap.print();
	}

	cout << "\nNow testing delete\n" << endl;

	for (int i = 0 ; i < 5 ; i++){
		heap.delete_min();
		heap.print();
	}

	return 0;

}
