
#ifndef _GRAPH
#define _GRAPH
#include <vector>
#include "edge.h"
#include<string>
/*http://stackoverflow.com/questions/6946217/pointer-to-a-vector*/
class Graph
{
public:
	int V();
	int E();
	Graph(int numVertices);
	Graph(std::string filename);
	~Graph();
	bool adjacent(int v1, int v2);
	std::vector<int>* neighbors(int v);
	void add_edge(int v1, int v2, double cost);
	void delete_edge(int v1, int v2);
	double get_node_value(int v);
	void set_node_value(int v, double dist);
	double get_edge_value(int v1, int v2);
	void set_edge_value(int v1, int v2, double cost);
	void displayGraph() const;
private:
	int numVertices, numEdges;
	std::vector< std::vector<double> > adjlist;
	std::vector<double> dist_vert;
};
#endif