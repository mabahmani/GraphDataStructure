template <class DT>
class Qnode
{
public:
	DT data;
	Qnode<DT> *next;
public:
	Qnode();
	Qnode(DT d);
	~Qnode();
};

template <class DT>
Qnode<DT>::Qnode()
{
	next = 0;
}

template <class DT>
Qnode<DT>::Qnode(DT d)
{
	data = d;
	next = 0;
}

template <class DT>
Qnode<DT>::~Qnode()
{
}

template <class DT>
class Queue
{
private:
	Qnode<DT> *head;
	Qnode<DT> *last;
public:
	Queue();
	~Queue();

	void push(DT v);
	DT pup();
	bool isEmpty();
};

template<class DT>
 Queue<DT>::Queue()
{
	head = 0;
	last = 0;
}

template<class DT>
 Queue<DT>::~Queue()
{
}

template<class DT>
 void Queue<DT>::push(DT v)
{
	Qnode<DT> *newItem = new Qnode<DT>(v);
	if (!head) {
		head = newItem;
		head->next = 0;
		last = head;
	}
	else
	{
		last->next = newItem;
		last = newItem;
		last->next = 0;
	}
}

 template<class DT>
  DT Queue<DT>::pup()
 {
	 Qnode<DT> *temp;
	 DT item;
	 if (!head) {
		 item = head->data;
		 return item;
	 }
	 else {
		 item = head->data;
		 temp = head;
		 head = head->next;
		 delete temp;
	 }
	 return item;
 }

  template<class DT>
bool Queue<DT>::isEmpty()
  {
	  if (!head)
		  return true;
	  return false;
  }
