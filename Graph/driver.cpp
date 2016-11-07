// Dijikstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include"ShortestPath.h"
#include"priorityQueue.h"
#include"MST.h"
#include"vertex.h"
#include <random>
#include<time.h>
#include<iostream>
#include<fstream>
#include<string>

void utility(int numVertices, double density, double dist_low, double dist_high)
{
	Graph G(numVertices);
	std::srand(static_cast<unsigned>(time(0)));
	for (int i = 0; i < numVertices; i++)
	{
		for (int j = 0; j < numVertices; j++)
		{
			if (i != j)
			{
				double rnd = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
				double cost = dist_low + rnd*(dist_high - dist_low);
				if (rnd < density)
				{
					G.add_edge(i, j, cost);
				}
			}
		}

	} 
	std::cout << "parameters for the graph are Density:" << density << " numVertices " << numVertices << " low_cost " << dist_low << " high_cost " << dist_high;
	std::cout << "\n Generated graph is as shown below." << std::endl;
	G.displayGraph();
	ShortestPath SP(G,0);
	int counter = 0;
	double path_sum = 0.0;
	for (int i = 1; i < numVertices; i++)
	{
			double cost = SP.path_size(0, i);
			if (cost >= 0)
			{
				counter++;
				path_sum += cost;
			}
	}
	std::cout <<std::endl << "Average path sum is   " << (path_sum/counter) << std::endl;
	Prim P(G, 0);
	P.displayMST();
	std::cout << " Cost of MST is " << P.tree_cost() << std::endl;
}

void utility2(std::string filename)
{
	Graph G(filename);
	G.displayGraph();
	Prim P(G, 0);
	P.displayMST();
	std::cout << " Cost of MST is " << P.tree_cost() << std::endl;
}



int main()
{
	int numvertices;
	double density, low_cost, high_cost;
	std::cout << "please enter the number of vertices for the input graph. " << std::endl;
	std::cin >> numvertices;
	std::cout << "enter density, cost lower bound, cost higher bound separated by spaces" << std::endl;
	std::cin >> density >> low_cost >> high_cost;
	/*http://stackoverflow.com/questions/10150468/how-to-redirect-cin-and-cout-to-files*/
	std::ofstream out("out.txt");
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt
	utility(numvertices, density, low_cost, high_cost);
	std::cout.rdbuf(coutbuf); //reset to standard output again
	
	// The below method is a test for MST(assignment 3), it creates a graph by reading it from a file.
	// and runs prims algorithm on it.
	//utility2("input.txt");

	
	// PriorityQueue Test.
	/*PQ<vertex> pq;
	pq.insert(vertex(1, 20));
	pq.insert(vertex(2, 30));
	pq.insert(vertex(3, 40));
	pq.insert(vertex(4, 50));
	pq.chgPriority(vertex(1, 20), 60);
	std::cout << std::endl<< pq.top().getVal() << endl;*/
    return 0;
}

