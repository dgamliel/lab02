#include "top_k.h"

Top_k::Top_k(unsigned int k);{
	HashTable hash;
	MinHeap   heap(k);	
}

void Top_k::insert(string s){
	if ( !heap.full() ){		
		//Checks membership of string
		//If string is not in heap -> insert	
		if (hash.get(s).second == -1){
			pair<string, int> p(s, 1);
			unsigned int index = heap.insert(p);
			hash(str, index);
		}

		//If the string is already in the heap
		//Then what we do is ...
		else if (hash.get(s).second != -1){
			//Get index of where element is currently located from hash to heap
			unsigned int index = hash.get(s).second;

			//Create new pair that increments the occurance of the string
			pair<string, int> new_p(s, hash.get(s).second + 1);

			//Set the heap value to occurances = occurances + 1 && peroclate down
			index = heap.set(index, new_p);

			//Sets the new hash value to be the new index that we percolated down to. 
			hash.set(s, index);	
		}

	}	
}

void Top_k::get(string s){
	
}
