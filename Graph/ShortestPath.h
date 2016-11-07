
#ifndef _SHORTEST_PATH
#define _SHORTEST_PATH
#include"Graph.h"
#include<list>
#include<vector>
class ShortestPath
{
public:
	// expects the input graph and the source vertex from which 
	// the shortest path is to be calculated.
	ShortestPath(Graph G, int src);
	std::list<int>* vertices();
	std::list<int>* path(int v); //returns a vector containing back-traced path from the given vertex to source.
	double path_size(int v1, int v2);
private:
	Graph G;
	const int src;
	std::vector<int> fromVert;
	std::vector<double> dist;
	void trigger(); // runs the dijikstra algorithm given the source on the input graph and populates the tables dist, fromVert.
};
#endif
