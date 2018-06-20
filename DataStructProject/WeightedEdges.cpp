#include "WeightedEdges.h"



WeightedEdges::WeightedEdges()
{
	weight = 9999;
}

WeightedEdges::WeightedEdges(int s, int d, int w)
{
	source = s;
	dist = d;
	weight = w;
}


WeightedEdges::~WeightedEdges()
{
}
