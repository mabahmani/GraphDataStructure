template <class DT>
class Node
{
public:
	DT data;
	Node<DT> *next;
public:
	Node();
	Node(DT d);
	~Node();
};

template <class DT>
Node<DT>::Node()
{
	next = 0;
}

template <class DT>
Node<DT>::Node(DT d)
{
	data = d;
	next = 0;
}

template <class DT>
Node<DT>::~Node()
{
}