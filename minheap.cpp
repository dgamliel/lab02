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
	unsigned int last_item_index = this->next_unused_index - 1;
	this->heap[1] = this->heap[last_item_index];
	this->next_unused_index--;

	this->percolate_down(1);
}

void MinHeap::insert(unsigned int occurances){
	//This works!! We insert item at the end
	this->heap[next_unused_index] = occurances;
	this->next_unused_index++;

    unsigned int i = next_unused_index;
    i--;
    unsigned int _child;
    unsigned int _parent;
 
    _child  = i;
    _parent = parent(i);
    while (_child != 1 && heap[_parent] > heap[_child] )
    {
        swap(&heap[_parent], &heap[_child]);
        _child  = parent(_child);
        _parent = parent(_child);
    }	

	
}

void MinHeap::percolate_down(unsigned int index){
	unsigned int parent, left, right;
	parent = index;
	left   = parent * 2;
	right  = left + 1;

	while (heap[parent] > heap[left] || heap[parent] > heap[right]){
		
		if (heap[left] > heap[right]){
			swap(&heap[parent], &heap[right]);
			parent = right;
		}

		else {
			swap(&heap[parent], &heap[left]);
			parent = left;
		}

		left = parent*2;
		right = left + 1;

		if (left > this->next_unused_index || right > this->next_unused_index){
			break;
		}

	}
}


void MinHeap::print(){
	for (unsigned int i = 1; i < this->next_unused_index; i++){
		cout << heap[i] << " ";
	}
	cout << endl;
}

void MinHeap::swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
