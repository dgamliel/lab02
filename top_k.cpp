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

	}


	if ( heap.full() && !hash.exists_in_heap(s){
		heap.set_string_at_index(s, 1);
	}


		//If item is already in the the heap and the heap is full
		if (hash.get(s).second != -1){
			//Get item data stored in hash
			pair<string, int> item_pair = hash.get(s);
			
			//Go to pair at minheap, update
			int index_in_heap = hash.get(s).second;
			pair<string, int> update_pair(heap.get(index_in_heap));
			update_pair.second = update_pair.second + 1;

			int updated_index = heap.set(index_in_heap, update_pair);

			//swap
			if (updated_index == index_in_heap){
				return;
			} 

			string swapped_string;
			int    swapped_index;
			swapped_index = updated_index / 2;
			swapped_string = heap.get(swapped_index).first;

			hash.set(s, updated_index);
			hash.set(swapped_string, swapped_index);

		}

	}
	
}


void Top_k::percolate_insert(pair<string, int> p){	
	
	if (heap.last() == 0){
		heap.set(1, p);
		return; 
	}

	//heap.insert(p);

	pair<string, int> parent_pair, child_pair;
	int child = heap.last();
	int parent = child / 2;

	while (child > 1 && heap.get(child).second < heap.get(parent).second){
			
			//Eager initialization of string int for pair	
			string parent_string, child_string;
			
			parent_pair = heap.get(parent);
			child_pair  = heap.get(child);

			heap.set(child, parent_pair);
			heap.set(parent, child_pair);

			hash.set(parent_string, child);
			hash.set(child_string, parent);

			child  = child / 2;
			parent = parent / 2; 

	}	
}
