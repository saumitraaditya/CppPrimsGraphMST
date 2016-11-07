#ifndef _MST
#define _MST
#include"Graph.h"
#include"edge.h"
class Prim
{
public:
	Prim(Graph G, int src);
	double tree_cost();
	std::vector<edge>* mst();
	void displayMST();

private:
	std::vector<bool>selected;
	std::vector<edge>* tree;
	std::vector<double>dist;
	std::vector<int>from;
	double cost_tree;
	Graph G;
	int src;
	void trigger();

};
#endif _MST
