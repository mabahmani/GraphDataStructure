#include "Graph.h"
#include <iostream>
using namespace std;
void main() {
	Graph g;
	Vertex v0(0);
	Vertex v1(1);
	Vertex v2(2);
	Vertex v3(3);
	Vertex v4(4);
	Vertex v5(5);
	Vertex v6(6);
	//Vertex v7(7);
	g.addVertex(v0);
	g.addVertex(v1);
	g.addVertex(v2);
	g.addVertex(v3);
	g.addVertex(v4);
	g.addVertex(v5);
	g.addVertex(v6);
	
	/*g.addVertex(v7);
	g.addEdge(v0, v1);
	g.addEdge(v0, v2);
	g.addEdge(v1, v3);
	g.addEdge(v1, v4);
	g.addEdge(v2, v5);
	g.addEdge(v2, v6);
	g.addEdge(v3, v7);
	g.addEdge(v4, v7);
	g.addEdge(v5, v7);
	g.addEdge(v6, v7);
	g.BFS(0);*/
	
	g.addEdge(v0, v1, 28);
	g.addEdge(v0, v5, 10);
	g.addEdge(v1, v2, 16);
	g.addEdge(v1, v6, 14);
	g.addEdge(v2, v3, 12);
	g.addEdge(v3, v4, 22);
	g.addEdge(v3, v6, 18);
	g.addEdge(v4, v5, 25);
	g.addEdge(v4, v6, 24);
	g.deleteEdge(v0, v1);
	g.deleteEdge(v0, v5);
	g.Components();
	//g.printWG();
	//g.Rashal();
	system("pause");
}