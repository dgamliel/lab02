#include "minheap.h"
#include <utility>
#include <iostream>
#include <string>

using namespace std;

MinHeap::MinHeap(unsigned int k){
	this->heap     = new pair<string,int>[k+1];
	this->MAX_CAPACITY = k+1;
	//Stores index of next item
	this->next_unused_index = 1;
}

MinHeap::~MinHeap(){
	delete [] this->heap;
}

unsigned int MinHeap::delete_min(){
	pair<string, int> min_val = this->heap[1];

	unsigned int last_item_index = this->next_unused_index - 1;
	this->heap[1] = this->heap[last_item_index];
	this->next_unused_index--;

	this->percolate_down(1);

	return min_val.second;
}

void MinHeap::set(unsigned int index, pair<string, int> p){
	heap[index] = p;
	percolate_down(index);	
}

void MinHeap::insert(pair<string, int> p){

	if ( this->full() ){
		this->heap[1] = p;
		return;
	} 


	//This works!! We insert item at the end
	this->heap[next_unused_index] = p;
	this->next_unused_index++;


	//takes index of next unused element
	//Subtracts 1 to access last item in array
    unsigned int i = next_unused_index;
    i--;

	//set up child, parent variables
    unsigned int _child;
    unsigned int _parent;
 
	//Child = last index
	//Parent = last index / 2
    _child  = i;
    _parent = parent(i);

	
    while (_child != 1 && heap[_parent].second > heap[_child].second )
    {
        swap(&heap[_parent], &heap[_child]);
        _child  = parent(_child);
        _parent = parent(_parent);
    }	

	
}

void MinHeap::percolate_down(unsigned int index){
	unsigned int parent, left, right;
	parent = index;
	left   = parent * 2;
	right  = left + 1;

	while (heap[parent].second > heap[left].second || heap[parent].second > heap[right].second){
		
		if (heap[left].second > heap[right].second){
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
		cout << "(" << heap[i].first << "," << heap[i].second << ")" << " ";
	}
	cout << endl;
}

void MinHeap::swap(pair<string, int> *a, pair<string, int> *b){
	pair<string, int> tmp = *a;
	*a = *b;
	*b = tmp;
}
