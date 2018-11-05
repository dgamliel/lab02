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

		string getStringAtIndex(unsigned int i){return heap[i].first;}
		int getOccurancesAtIndex(unsigned int i){return heap[i].second;}



		//Inserts and delete
		pair<string, int> get_min();
		unsigned int delete_min();
		void insert(pair<string, int> p);
		int set(unsigned int index, pair<string, int> p);
	
		//Percolate functions
		int percolate_down(unsigned int index);

		//Capacity
		int last(){return this->next_unused_index - 1;}
		bool full(){return next_unused_index == (MAX_CAPACITY + 1);}

		//parent & child functions
		unsigned int parent(unsigned int i){return i/2;}
		unsigned int right(unsigned int i){return (i*2)+1;}
		unsigned int left(unsigned int i){return (i*2);}


		//Other
		void print();
		void swap(pair<string, int> *a, pair<string, int> *b);

	private:
		unsigned int next_unused_index;
		unsigned int MAX_CAPACITY;
		pair<string, int> *heap;

};

#endif
