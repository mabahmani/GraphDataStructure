
class WeightedEdges
{
	friend class Graph;
public:
	int source;
	int dist;
	int weight;
public:
	WeightedEdges();
	WeightedEdges(int s,int d,int w);
	~WeightedEdges();
};

