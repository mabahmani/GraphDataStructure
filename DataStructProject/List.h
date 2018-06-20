#include "Node.h"
template <class DT>
class List
{
	friend class Graph;
private:
	Node<DT> *first;
	Node<DT> *last;
public:
	List();
	void Add(DT n);
	void deleteNode(DT n);
	void deleteFirst();
	bool search(DT n);
	void sort();
	bool isEmpty();
	void print();
	void printWG();
	~List();
};

template <class DT>
List<DT>::List()
{
	first = 0;
	last = 0;
}

template<class DT>
void List<DT>::Add(DT n)
{
	Node<DT> *newNode = new Node<DT>(n);
	if (!first) {
		first = newNode;
		first->next = 0;
		last = first;
	}
	else
	{
		last->next = newNode;
		last = newNode;
		last->next = 0;
	}
}

template<class DT>
void List<DT>::deleteNode(DT n)
{
	Node<DT> *current = first;
	Node<DT> *currentP = current;

	while (current) {
		if (current->data.number == n.number) {
			if (current == first) {
				first = first->next;
				delete current;
				return;
			}

			if (!current->next)
			{
				last = currentP;
				currentP->next = 0;
				delete current;
				return;
			}
			else {
				currentP->next = current->next;
				delete current;
				return;
			}
		}
		currentP = current;
		current = current->next;
	}
}

template<class DT>
void List<DT>::deleteFirst()
{
	if (!first) {
		return;
	}
	else {
		first = first->next;
	}
}

template<class DT>
 bool List<DT>::search(DT n)
{
	Node<DT> *current = first;
	if (!first) {
		return false;
	}
	else
	{
		while (current)
		{
			if (current->data.number == n.number)
			{
				return true;
			}
			current = current->next;
		}
	}
	return false;
}

 template<class DT>
 void List<DT>::sort()
 {
	 Node<DT> *current = first;
	 Node<DT> temp;
	 int counter = 0;

	 while (current)
	 {
		 counter++;
		 current = current->next;
	 }

	 for (int i = 0; i < counter - 1; i++)
	 {
		 current = first;
		 for (int j = 0; j < counter - 1 - i; j++)
		 {
			 if (current->data.weight > current->next->data.weight)
			 {
				 temp.data = current->data;
				 current->data = current->next->data;
				 current->next->data = temp.data;
			 }
			 current = current->next;
		 }
	 }
 }

 template<class DT>
  bool List<DT>::isEmpty()
 {
	 if (!first)
		 return true;
	 return false;
 }


 template<class DT>
 void List<DT>::print()
 {
	 Node<DT> *current = first;
	 while (current)
	 {
		 cout << current->data.number << " -> ";
		 current = current->next;
	 }
	 cout << "NULL" << "\n\n";
 }

 template<class DT>
 void List<DT>::printWG()
 {
	 Node<DT> *current = first;
	 while (current)
	 {
		 cout <<"(" << current->data.weight << ") " << current->data.number << " -> ";
		 current = current->next;
	 }
	 cout << "NULL" << "\n\n";
 }

template <class DT>
List<DT>::~List()
{
}

