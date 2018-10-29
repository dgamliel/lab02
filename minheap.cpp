#include "minheap.h"
#include <iostream>

MinHeap::MinHeap(unsigned int k){
	this->CAPACITY = k;
	this->heap = new unsigned int[CAPACITY+1];
	//Stores index of next item
	this->heap[0] = 1;
}

MinHeap::~MinHeap(){
	delete [] this->heap;
}


