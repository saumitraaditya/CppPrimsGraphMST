#include"stdafx.h"
#include "ShortestPath.h"
#include"PriorityQueue.h"
#include "vertex.h"
#include<list>
#include<vector>


ShortestPath::ShortestPath(Graph G, int src) :G(G), src(src) {
	fromVert.resize(G.V(), -1);
	dist.resize(G.V(), 999999.0);
	trigger();

}

std::list<int>* ShortestPath::vertices()
{
	std::list<int>* l = new std::list<int>();
	return l;
}

void ShortestPath::trigger()
{
	// we need a priority queue and a vector keeps track of the vertices selected in the shortest path forest.
	std::vector<bool>selected(G.V(), false);
	PQ<vertex> pq;
	//insert the source vertex in the pq
	pq.insert(vertex(src, 0.0));
	dist.at(src) = 0.0;
	while (pq.size() != 0)
	{
		int vertID = pq.minPriority().getID();
		selected.at(vertID) = true;
		std::vector<int>* neighborList = G.neighbors(vertID);
		for (int v : *neighborList)
		{
			if (selected.at(v) != true)
			{
				if (dist.at(vertID) + G.get_edge_value(vertID, v) < dist.at(v))
				{
					dist.at(v) = dist.at(vertID) + G.get_edge_value(vertID, v); //updates cost
					fromVert.at(v) = vertID; //update parent
					if (pq.contains(vertex(v, 0.0)))
						pq.chgPriority(vertex(v, dist.at(v)), dist.at(v));
					else
						pq.insert(vertex(v, dist.at(v)));
				}
			}
		}
		//delete neighborlist to free memory
		delete(neighborList);
	}
}

double ShortestPath::path_size(int src, int dst)
{
	return dist.at(dst);
}

std::list<int>* ShortestPath::path(int dst)
{
	std::list<int>* path_list = new std::list<int>();
	int temp = dst;
	while (fromVert.at(temp) != -1)
	{
		path_list->push_back(fromVert.at(temp));
		temp = fromVert.at(temp);
	}
	return path_list;
}
