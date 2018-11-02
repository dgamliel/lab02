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
		
	private:
		HashTable hash;
		MinHeap   heap;
};

#endif
