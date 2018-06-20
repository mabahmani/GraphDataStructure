#include "Vertex.h"

Vertex::Vertex()
{
	number = 1;
	weight = -1;
}

Vertex::Vertex(int v)
{
	number = v;
	weight = -1;
}

Vertex::Vertex(int v, int w)
{
	number = v;
	weight = w;
}
