#include "Graph.h"
#include <iostream>
using namespace std;


Graph::Graph()
{
	headNodes = new List<Vertex>[100];
	numberOfVertices = 0;
	numberOfEdges = 0;
}


Graph::~Graph()
{
}

void Graph::addVertex(Vertex v)
{
	if (!vertices.search(v))
	{
		vertices.Add(v);
		numberOfVertices++;
	}
}

void Graph::addEdge(Vertex s, Vertex d)
{
	headNodes[s.number].Add(d);
	headNodes[d.number].Add(s);
	numberOfEdges++;
}

void Graph::addDirectedEdge(Vertex s, Vertex d)
{
	headNodes[s.number].Add(d);
	numberOfEdges++;
}

void Graph::addEdge(Vertex s, Vertex d, int weight)
{
	Vertex D(d.number, weight);
	headNodes[s.number].Add(D);

	Vertex S(s.number, weight);
	headNodes[d.number].Add(S);

	WeightedEdges E(s.number, d.number, weight);
	heapEdges.push(E);

	numberOfEdges++;
}

void Graph::addDirectedEdge(Vertex s, Vertex d, int weight)
{

	Vertex S(s.number, weight);
	headNodes[d.number].Add(S);

	WeightedEdges E(s.number, d.number, weight);
	heapEdges.push(E);

	numberOfEdges++;
}

void Graph::deleteVertex(Vertex v)
{
	for (int i = 0; i < numberOfVertices; i++)
	{
		headNodes[i].deleteNode(v);
		numberOfEdges--;
	}
	vertices.deleteNode(v);
	numberOfVertices--;
}

void Graph::deleteEdge(Vertex u, Vertex v)
{
	headNodes[u.number].deleteNode(v);
	headNodes[v.number].deleteNode(u);
	numberOfEdges--;
}

void Graph::DFS(Vertex s)
{
	visited = new bool[numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
		visited[i] = false;
	DFS(s.number);
	delete [] visited;
}

void Graph::DFS(int v)
{
	Node<Vertex> *current;
	visited[v] = true;
	cout << v <<"  ";
	current = headNodes[v].first;
	while (current)
	{
		if (!visited[current->data.number]) {
			DFS(current->data.number);
		}
		current = current->next;
	}
}

void Graph::BFS(int v)
{
	Node<Vertex> *current;
	visited = new bool[numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
		visited[i] = false;

	visited[v] = true;
	Queue <int> q;
	q.push(v);
	while (!q.isEmpty())
	{
		v = q.pup();
		cout << v << "  ";
		current = headNodes[v].first;
		while (current)
		{
			if (!visited[current->data.number]) {
				q.push(current->data.number);
				visited[current->data.number] = true;
			}
			current = current->next;
		}
	}
	delete[] visited;
}

void Graph::Components() {
	visited = new bool[numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
		visited[i] = false;
	for (int i = 0; i < numberOfVertices; i++)
	{
		if (!visited[i])
		{
			DFS(i);
		}
		cout << endl;
	}
}

void Graph::spanningTree()
{
	visited = new bool[numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
		visited[i] = false;
	Graph T;
	T.numberOfVertices = numberOfVertices;
	spanningTree(0, T);
	T.print();
	delete[] visited;
}

void Graph::spanningTree(int v, Graph T)
{
	Node<Vertex> *current;
	visited[v] = true;

	current = headNodes[v].first;
	while (current)
	{
		if (!visited[current->data.number]) {
			Vertex s(v);
			Vertex d(current->data.number);
			T.addEdge(s, d);
			spanningTree(current->data.number,T);
		}
		current = current->next;
	}
}

bool Graph::hasCycle(Vertex s)
{
	visited = new bool[numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
		visited[i] = false;

	for (int u = 0; u < numberOfVertices; u++)
		if (!visited[u])
			if (hasCycle(u, -1))
				return true;
	return false;
}

bool Graph::hasCycle(int v, int parent)
{
	Node<Vertex> *current;
	visited[v] = true;

	current = headNodes[v].first;
	while (current)
	{
		if (!visited[current->data.number]) {
			if (hasCycle(current->data.number, v))
				return true;
		}
		else if (current->data.number != parent)
			return true;

		current = current->next;
	}
	return false;
}


void Graph::Rashal()
{
	Graph T;
	WeightedEdges temp;
	T.numberOfVertices = numberOfVertices;

	while (T.numberOfEdges != numberOfVertices - 1)
	{
		temp = heapEdges.pop();
		Vertex s(temp.source);
		Vertex d(temp.dist);
		T.addEdge(s, d, temp.weight);

		if (T.hasCycle(s))
		{
			T.deleteEdge(s, d);
		}
	}
	T.printWG();
}

void Graph::Prim()
{
	Graph T;
	Node<Vertex> *current;

	visited = new bool[numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
		visited[i] = false;

	visited[0] = true;
	while (T.numberOfEdges != numberOfVertices - 1)
	{
		WeightedEdges newEdge;
		for (int i = 0;i < numberOfVertices; i++)
		{
			if (visited[i])
			{
				current = headNodes[i].first;
				while (current)
				{
					if (!visited[current->data.number] && current->data.weight < newEdge.weight) 
					{
						newEdge.source = i;
						newEdge.dist = current->data.number;
						newEdge.weight = current->data.weight;
					}
					current = current->next;
				}
			}
		}
		Vertex s(newEdge.source); T.addVertex(s);
		Vertex d(newEdge.dist); T.addVertex(d);
		
		visited[d.number] = true;

		T.addEdge(s, d, newEdge.weight);
	}
	T.printWG();
}

void Graph::Solin()
{
	Graph T;
	visited = new bool[numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
		visited[i] = false;

	for (int i = 0; i < numberOfVertices; i++)
	{
		headNodes[i].sort();
		if (!visited[i] || !visited[headNodes[i].first->data.number])
		{
			visited[i] = true;
			visited[headNodes[i].first->data.number] = true;
			Vertex s(i); T.addVertex(s);
			Vertex d(headNodes[i].first->data.number); T.addVertex(d);
			T.addEdge(s, d, headNodes[i].first->data.weight);
		}
	}

	int i = 0;
	while (T.numberOfEdges != T.numberOfVertices - 1)
	{
		if (headNodes[i].first->next->data.weight < headNodes[headNodes[i].first->data.number].first->next->data.weight) {
			Vertex s(i); T.addVertex(s);
			Vertex d(headNodes[i].first->next->data.number); T.addVertex(d);
			T.addEdge(s, d, headNodes[i].first->next->data.weight);
		}
		else {
			Vertex s(headNodes[i].first->data.number); T.addVertex(s);
			Vertex d(headNodes[headNodes[i].first->data.number].first->next->data.number); T.addVertex(d);
			T.addEdge(s, d, headNodes[headNodes[i].first->data.number].first->next->data.weight);
		}
	}

	T.printWG();
}

void Graph::print()
{
	for (int i = 0; i < numberOfVertices; i++)
	{
		cout << "Head(" << i << ") -> ";
		headNodes[i].print();
	}
}

void Graph::printWG()
{
	for (int i = 0; i < numberOfVertices; i++)
	{
		cout << "Head(" << i << ") -> ";
		headNodes[i].printWG();
	}
}