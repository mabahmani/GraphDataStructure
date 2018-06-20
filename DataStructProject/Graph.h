#include"Vertex.h"
#include"WeightedEdges.h"
#include"List.h"
#include"Queue.h"
#include"MinHeap.h"
class Graph
{
private:
	List<Vertex> *headNodes;
	List<Vertex> vertices;
	MinHeap<WeightedEdges> heapEdges;
	int numberOfVertices;
	int numberOfEdges;
	bool *visited;
public:
	Graph();
	~Graph();

	void addVertex(Vertex v);
	void addEdge(Vertex s, Vertex d);
	void addDirectedEdge(Vertex s, Vertex d);
	void addEdge(Vertex s, Vertex d, int weight);
	void addDirectedEdge(Vertex s, Vertex d, int weight);
	void deleteVertex(Vertex v);
	void deleteEdge(Vertex u, Vertex v);
	void DFS(Vertex s);
	void DFS(int v);
	void BFS(int v);
	void Components();
	void spanningTree();
	void spanningTree(int v, Graph T);
	bool hasCycle(Vertex s);
	bool hasCycle(int v, int parent);
	void Rashal();
	void Prim();
	void Solin();
	void print();
	void printWG();
};