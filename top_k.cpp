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

	if ( heap.full() ){
		//If heap is full and string is not in the heap
		if (hash.get(s).second == -1){
			//Copy amount of occurances from least occuring item in heap
			unsigned int occurances = heap.get_min().second;

			//Create new pair to be inserted to minheap
			pair<string, int> p(str, occurances);

			//Pop min off
			heap.delete_min();	
	
			//insert our new pair into the heap
			heap.insert(p);

			//Update our table making our inserted string point to top of minheap
			hash.insert(str, 1);
		}


		//If item is already in the the heap and the heap is full
		if (hash.get(s).second != -1){
			unsigned int 
		}

	}
	
}

void Top_k::get(string s){
	
}








