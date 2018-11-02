#include "top_k.h"
#include "minheap.h"
#include "hashtable.h"

Top_k::Top_k(unsigned int k){
	HashTable hash;
	MinHeap heap(k);	
}

void Top_k::insert(string s){
	if ( !heap.full() ){		
		//Checks membership of string
		//If string is not in heap -> insert	
		if (hash.get(s).second == -1){
			//Create string to be inserted with value 1
			pair<string, int> p(s, 1);
	
			//Percolates up, returns indicies that are swapped when percolated
			this->percolate_insert(p);
		}

		//If the string is already in the heap
		//Then what we do is ...
		else if (hash.get(s).second != -1){
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

	if ( heap.full() ){
		//If heap is full and string is not in the heap
		if (hash.get(s).second == -1){
			//Get pair to be deleted
			pair<string, int> delete_item = heap.get_min();

			//specific pair item values
			string delete_string     = delete_item.first;
			unsigned int occurances  = delete_item.second;

			//Create new pair to be inserted to minheap
			pair<string, int> p(s, occurances);

			//Pop min off
			heap.delete_min();	
	
			//insert our new pair into the heap
			heap.insert(p);

			//Update our table making our inserted string point to top of minheap
			hash.insert(s, 1);
			
			//Set the index of our deleted string to be negative 1
			hash.set(delete_string, -1);
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
