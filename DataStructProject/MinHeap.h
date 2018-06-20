template <class DT>

class MinHeap {
private:
	int maxSize;
	DT *heap;
	int currentSize;
public:
	MinHeap();
	MinHeap(int size);
	void push(DT e);
	DT pop();
};

template<class DT>
inline MinHeap<DT>::MinHeap()
{
	maxSize = 100;
	heap = new DT[maxSize + 1];
}

template<class DT>
inline MinHeap<DT>::MinHeap(int size)
{
	maxSize = size;
	heap = new DT[maxSize + 1];
}



template<class DT>
inline void MinHeap<DT>::push(DT e)
{
	if (currentSize == maxSize) return;
	currentSize++;
	int i;
	for ( i = currentSize; 1 ;)
	{
		if (i == 1) break;
		if (e.weight >= heap[i / 2].weight) break;
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = e;
}

template<class DT>
inline DT MinHeap<DT>::pop()
{
	DT item = heap[1];
	DT k = heap[currentSize];
	currentSize--;
	int i, j;
	for ( i = 1,j=2; j < currentSize;)
	{
		if (j < currentSize) if (heap[j].weight > heap[j + 1].weight) j++;
		if (k.weight <= heap[j].weight) break;
		heap[i] = heap[j];
		i = j; j *= 2;
	}
	heap[i] = k;

	return item;
}
