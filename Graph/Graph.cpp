# include "stdafx.h"
# include "Graph.h"
# include <iostream>
#include<fstream>
#include<sstream>
using namespace std;
/*http://stackoverflow.com/questions/6946217/pointer-to-a-vector*/
Graph::Graph(int numVertices) :numVertices(numVertices) 
{
	adjlist.resize(numVertices);
	dist_vert.resize(numVertices, -1.0);
	for (int i = 0; i < numVertices; i++)
		adjlist[i].resize(numVertices,-1.0);
}

Graph::Graph(std::string filename)
{
	std::ifstream input(filename);
	std::string line; 
	std::getline(input, line);
	numVertices = std::stoi(line);
	adjlist.resize(numVertices);
	dist_vert.resize(numVertices, -1.0);
	for (int i = 0; i < numVertices; i++)
		adjlist[i].resize(numVertices, -1.0);
	while (std::getline(input, line))
	{
		std::istringstream iss(line);
		int src, dst;
		double cost;
		if (iss >> src >> dst >> cost)
		{
			this->add_edge(src, dst, cost);
		}
		else
			break;
	}

}
Graph::~Graph()
{
}
int Graph::V() { return numVertices; }
int Graph::E() { return numEdges; }
void Graph::add_edge(int v1, int v2, double cost)
{
	if (v1 < 0 && v1 >= numVertices)
		return;
	if (v2 < 0 && v2 >= numVertices)
		return;
	if (adjlist[v1][v2] != -1.0)
		return;
	adjlist[v1][v2] = cost;
	adjlist[v2][v1] = cost;
}

void Graph::displayGraph() const
{
	for (size_t i = 0; i < adjlist.size(); i++)
	{
		for (size_t j = 0; j < adjlist[i].size(); j++)
			std::cout << adjlist[i][j]<< "\t";
		std::cout << std::endl;
	}
}

void Graph::delete_edge(int v1, int v2)
{
	if (adjlist[v1][v2] == 0.0)
		return;
	else
		adjlist.at(v1).at(v2) = 0;
}

double Graph::get_edge_value(int v1, int v2)
{
	return adjlist[v1][v2];
}

void Graph::set_edge_value(int v1, int v2, double cost)
{
	adjlist[v1][v2] = cost;
}

double Graph::get_node_value(int v1)
{
	return dist_vert.at(v1);
}

void Graph::set_node_value(int v1, double dist)
{
	dist_vert.at(v1) = dist;
}

std::vector<int>* Graph::neighbors(int v)
{
	std::vector<int>* n = new std::vector<int>();
	for (int i =0 ;i<numVertices;i++)
	{
		if (adjlist.at(v).at(i) != -1)
			n->push_back(i);
	}
	return n;
}

bool Graph::adjacent(int v1, int v2)
{
	return (adjlist.at(v1).at(v2) != -1);
}





