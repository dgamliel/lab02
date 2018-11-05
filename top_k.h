#include "minheap.h"
#include "hashtable.h"
#include <string>

#ifndef DGAM_TOP_K
#define DGAM_TOP_K

class Top_k{
	public:
		Top_k();
		void insert(string s);
	
		//Print heap & hash
		void print_heap(){heap.print();}
		void print_hash(){hash.print();}

		void swap_indicies_after_percolate(int top_index, int bottom_index);
	
	private:
		HashTable hash;
		MinHeap   heap;
};

#endif
