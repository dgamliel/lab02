#include <utility>
#include <cstdlib>
#include <string>
#include <iostream>


#ifndef DGAM_MIN_HEAP
#define DGAM_MIN_HEAP

using namespace std;

class MinHeap{
	public:
		MinHeap(); 
		MinHeap(unsigned int k);
		~MinHeap();

		//Getters and Setters
		pair<string, int> get(unsigned int i){return heap[i];}

		//Inserts and delete
		pair<string, int> get_min();
		unsigned int delete_min();
		void insert(pair<string, int> p);
		int set(unsigned int index, pair<string, int> p);
	
		//Percolate functions
		int percolate_down(unsigned int index);

		//Other
		int last(){return this->next_unused_index - 1;}
		bool full(){return next_unused_index == (MAX_CAPACITY + 1);}
		void print();
		unsigned int parent(unsigned int i){return i/2;}
		void swap(pair<string, int> *a, pair<string, int> *b);

	private:
		unsigned int next_unused_index;
		unsigned int MAX_CAPACITY;
		pair<string, int> *heap;

};

#endif
