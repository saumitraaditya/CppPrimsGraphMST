#include"stdafx.h"
#include"MST.h"
#include"vertex.h"
#include"edge.h"
#include"PriorityQueue.h"
#include<iostream>

Prim::Prim(Graph G, int src) :G(G), src(src)
{
	dist.resize(G.V(), 999999);
	from.resize(G.V(), -1);
	selected.resize(G.V(), false);
	tree = new std::vector<edge>();
	cost_tree = 0.0;
	trigger();
}

void Prim::trigger()
{
	PQ<vertex> pq;
	//start with the source vertex.
	dist.at(src) = 0.0;
	selected.at(src) = true;
	for (auto dst : *G.neighbors(src))
	{
		auto cost = G.get_edge_value(src, dst);
		if (selected.at(dst) == false && cost < dist.at(dst))
		{
			dist.at(dst) = cost;
			from.at(dst) = src;
			pq.insert(vertex(dst, cost));
		}
	}

	while (pq.size() != 0)
	{
		int vertID = pq.minPriority().getID();
		tree->push_back(edge(from.at(vertID), vertID,dist.at(vertID)));
		cost_tree += dist.at(vertID);
		selected.at(vertID) = true;
		for (auto dst : *G.neighbors(vertID))
		{
			auto cost = G.get_edge_value(vertID, dst);
			if (selected.at(dst) == false && cost < dist.at(dst))
			{
				dist.at(dst) = cost;
				from.at(dst) = vertID;
				vertex tmp = vertex(dst, cost);
				if (!pq.contains(tmp))
					pq.insert(vertex(dst, cost));
				else
					pq.chgPriority(tmp, cost);
			}
		}
		
	}
}

double Prim::tree_cost()
{
	return cost_tree;
}

std::vector<edge>* Prim::mst()
{
	return tree;
}

void Prim::displayMST()
{
	std::cout << " MST of given graph is as below" << std::endl;
	for (auto edge : *tree)
	{
		std::cout << "(" << edge.getSrc() << "," << edge.getDst() << "," << edge.getCost() << ")\t";
	}
	std::cout << std::endl;
}