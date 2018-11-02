#include "minheap.h"
#include "hashtable.h"
#include <string>

#ifndef DGAM_TOP_K
#define DGAM_TOP_K

class Top_k{
	public:
		Top_k(unsigned int k);
		void insert(string s);
		void get(string s);

		//Percolate function
		void percolate_insert(pair<string, int> p);
	
		//Print heap & hash
		void print_heap(){heap.print();}
		void print_hash(){hash.print();}
	
	private:
		HashTable hash;
		MinHeap   heap;
};

#endif
