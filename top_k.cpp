#include "top_k.h"
#include "minheap.h"
#include "hashtable.h"

Top_k::Top_k(unsigned int k){
	HashTable hash;
	MinHeap heap(k);	
}

void Top_k::insert(string s){

	//Case: Heap not fully and item not in heap
	if ( !heap.full() && !hash.exists_in_heap(s)){		
		pair<string, int> p(s, 1);
		int new_index = this->heap.insert(p);
		//Does not account for all the possible swaps that could have been made. 
		hash.setIndexAtString(s, new_index); 
	}

	else if (!heap.full() && hash.exists_in_heap(s)){
		return;
	}


	else if ( heap.full() && !hash.exists_in_heap(s)){
		string popped_string = heap.get_min().first;
		heap.set_string_at_index(s, 1);

		//update indicies
		hash.setIndexAtString(popped_string, -1);
		hash.setIndexAtString(s, 1);
	}

	else if (heap.full() && hash.exists_in_heap(s)){
		//locate index location of s & get/increment occurances
		int index_of_s = hash.getIndexAtString(s);
		int occurances = heap.get_occurances_at_index(index_of_s);
		occurances++;

		//set value of occurances to be incremented & percolate down
		heap.set_occurances_at_index(index_of_s, occurances);
		int end_index = heap.percolate_down(index_of_s);
		swap_indicies_after_percolate(index_of_s, end_index);
		hash.setIndexAtString(s, index_of_s);
	}
}

void Top_k::swap_indicies_after_percolate(int top_index, int bottom_index){
	int i = bottom_index;
	while (i != top_index){
		string str_to_update = heap.get_string_at_index(i);
		hash.setIndexAtString(str_to_update, i);

		//Update loop var
		i = heap.parent(i);
	}
}
