#ifndef DGAM_MIN_HEAP
#define DGAM_MIN_HEAP

class MinHeap{
	public: 
		MinHeap(unsigned int k);
		~MinHeap();

		//Inserts and delete
		unsigned int get_min(){return this->heap[1];}
		void delete_min();
		void insert(unsigned int occurances);
	
		//Percolate functions
		void percolate_down(unsigned int index);
		void percolate_up();

		void print();

	private:
		unsigned int next_unused_index;
		unsigned int MAX_CAPACITY;
		int *heap;
		void swap(int *a, int *b);
};

#endif
