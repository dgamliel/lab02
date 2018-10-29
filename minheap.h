#ifndef DGAM_MIN_HEAP
#define DGAM_MIN_HEAP

class MinHeap{
	public: 
		MinHeap(unsigned int k);
		~MinHeap();

		unsigned int get_min();
		void delete_min();
		void insert();

	private:
		unsigned int *heap;
		unsigned int CAPACITY;
		void percolate_down(unsigned int index);
		void percolate_up(unsigned int index);
};
