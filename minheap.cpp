#include "minheap.h"
#include <iostream>

using namespace std;

MinHeap::MinHeap(unsigned int k){
	this->heap     = new int[k+1];
	this->MAX_CAPACITY = k+1;
	//Stores index of next item
	this->next_unused_index = 1;
}

MinHeap::~MinHeap(){
	delete [] this->heap;
}

void MinHeap::delete_min(){
	unsigned int last_index = this->heap[0];
	this->heap[0] = this->heap[0] - 1;
	this->heap[1] = this->heap[last_index];
	
	this->percolate_down(1);
}

void MinHeap::insert(unsigned int occurances){
	cout << "in this function!!" << endl;
	//This works!! We insert item at the end
	this->heap[next_unused_index] = occurances;
	this->next_unused_index++;
	
	unsigned int i = next_unused_index;
	i--;
	unsigned int _child;
	unsigned int _parent;

	_child  = i;
	_parent = parent(i);
	while (heap[_parent] > heap[_child] && _child != 1)
	{
		cout << "reach this code!" << endl;
		swap(&heap[_parent], &heap[_child]);
		_child  = parent(_child);
		_parent = parent(_child); 
	}
	
}

void MinHeap::percolate_down(unsigned int index){
	return;
}

void MinHeap::percolate_up(){
return;

}

void MinHeap::print(){
	for (int i = 1; i < this->next_unused_index; i++){
		cout << heap[i] << " ";
	}
	cout << endl;
}

void MinHeap::swap(int *a, int *b){
	int *tmp = a;
	*a = *b;
	*b = *tmp;
}
