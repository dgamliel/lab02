#include "minheap.h"
#include <utility>
#include <iostream>
#include <string>
 
using namespace std;
 
 
MinHeap::MinHeap(){
    this->heap[16] ;
    this->MAX_CAPACITY = 16;
    //Stores index of next item
    this->num_elements = 0;

}

 
unsigned int MinHeap::delete_min(){
    pair<string, int> min_val = this->heap[1];
 
    this->heap[1] = this->heap[num_elements];
    this->num_elements--;
 
    this->percolate_down(1);
 
    return min_val.second;
}
 
int MinHeap::set(unsigned int index, pair<string, int> &p){
    heap[index] = p;
    return percolate_down(index);
}
 
int MinHeap::insert(pair<string, int> &p){
 
    if ( this->full() ){
        this->heap[1] = p;
        return 1;
    }
 
 
    //This works!! We insert item at the end
    if (this->num_elements < this->MAX_CAPACITY){
        this->num_elements++;
    } 

	if (this->num_elements == 0 || this->num_elements == 1){
		cout << 'hello' << endl;
		this->heap[1] = p;
		return -1;
	}
 
    //takes index of next unused element
    //Subtracts 1 to access last item in array
    unsigned int i = num_elements;
 
    //set up child, parent variables
    unsigned int _child;
    unsigned int _parent;
 
    //Child = last index
    //Parent = last index / 2
    _child  = i;
    _parent = parent(i);
 
 
    while (_child != 1 && heap[_parent].second > heap[_child].second )
    {
		cout << "ddd"<<heap[_parent].first << ", " << heap[_child].first << endl;
        swap(heap[_parent], heap[_child]);
        _child  = parent(_child);
        _parent = parent(_parent);
    }

	return _child;
}
 
int MinHeap::percolate_down(unsigned int index){
    unsigned int parent, left, right;
    parent = index;
    left   = parent * 2;
    right  = left + 1;
 
    while (heap[parent].second > heap[left].second || heap[parent].second > heap[right].second){
 
        if (heap[left].second > heap[right].second){
            swap(heap[parent], heap[right]);
            parent = right;
        }
 
        else {
            swap(this->heap[parent], this->heap[left]);
            parent = left;
        }
 
        left = parent*2;
        right = left + 1;
 
        if (left > this->num_elements+1 || right > this->num_elements+1){
            break;
        }
 
    }
 
    return parent;
 
}
 
 
void MinHeap::print(){
    for (unsigned int i = 1; i < this->last(); i++){
        cout << "(" << heap[i].first << "," << heap[i].second << ")" << " ";
    }
    cout << endl;
}
 
void MinHeap::swap(pair<string, int> &a, pair<string, int> &b){
    pair<string, int> tmp(a);
    a = b;
    b = tmp;
}
 
pair<string, int> MinHeap::get_min(){
    if (this->get_num_elements() == 0){
        pair<string, int> p("", -1);
        return p;
    }
 
    else {return this->heap[1];}
}