#include "minheap.h"
#include <iostream>

using namespace std;

MinHeap::MinHeap(unsigned int k){
	this->heap     = new unsigned int[k+1];
	this->MAX_CAPACITY = k+1;
	//Stores index of next item
	this->heap[0]  = 1;
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

	if (this->heap[0] == 1)
	{
		this->heap[1] = occurances;
		this->heap[0] = this->heap[0] + 1;
		return;
	}

	unsigned int last_index = this->heap[0];
	this->heap[last_index] = occurances;

	this->percolate_up(occurances);	
	this->heap[0] = this->heap[0] + 1;
}

void MinHeap::percolate_down(unsigned int index){
	return;
}

void MinHeap::percolate_up(unsigned int index){
	unsigned int child_index, parent_index, child_val, parent_val;

	child_index  = this->heap[0];
	parent_index = index / 2;

	child_val  = this->heap[child_index];
	parent_val = this->heap[parent_index];
 
	if (this->heap[0] == 1){
		this->heap[1] = index;
		return;
	}


	while (child_index != 1 && (child_val < parent_val)){
		//Swap parent and child
		//unsigned int tmp = parent_val;
		this->heap[parent_index] = child_val;
		this->heap[child_index]  = parent_val;
	
		//Update values
		child_index  = parent_index;
		parent_index = parent_index / 2;

		child_val  = this->heap[child_index];
		parent_val = this->heap[parent_index];
	}
}

void MinHeap::print(){
	unsigned int CAPACITY = this->heap[0];

	if (this->heap[0] == 1){
		cout << "[ " << this->heap[0] << " ]" << endl;
		return;
	}

	cout << "[ " ;
	for (unsigned int i = 1; i < CAPACITY - 1; i++){
		cout << this->heap[i] << ", ";
	}
	cout << this->heap[CAPACITY] << " ]" << endl;
}
