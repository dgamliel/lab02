#ifndef DGAM_MIN_HEAP
#define DGAM_MIN_HEAP

class MinHeap{
	public: 
		MinHeap(unsigned int k);
		~MinHeap();

		unsigned int get_min(){return this->heap[1];}
		void delete_min();
		void insert(unsigned int occurances);

		void print();

	private:
		unsigned int *heap;
		unsigned int MAX_CAPACITY;
		void percolate_down(unsigned int index);
		void percolate_up(unsigned int index);
};

#endif
