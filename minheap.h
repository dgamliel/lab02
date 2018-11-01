#ifndef DGAM_MIN_HEAP
#define DGAM_MIN_HEAP

class MinHeap{
	public: 
		MinHeap(unsigned int k);
		~MinHeap();

		unsigned int get_min(){return this->heap[1];}
		void delete_min();
		void insert(unsigned int occurances);

		unsigned int parent(unsigned int i){return i/2;}
		unsigned int left(unsigned int i){return i * 2;}
		unsigned int right(unsigned int i){return (i * 2) + 1;}


		void print();

	private:
		unsigned int next_unused_index;
		unsigned int MAX_CAPACITY;
		int *heap;

		void percolate_down(unsigned int index);
		void percolate_up();
		void swap(int *a, int *b);
};

#endif
