#pragma once
#include <limits.h>
#include "weightedgraph.h"
#include "linkedlist.hpp"

class UndirectedGraph :
	public WeightedGraph
{
public:
	UndirectedGraph(int mVertices);

	void set(int, int, int); // Sets a vertex at both (i,j) and (j,i) with a weight.
	void set(int, int);      // Sets a vertex at both (i,j) and (j,i) with 1.
							 // This method should call the 3-parameter set method
							 // as set(i,j,1);

	LinkedList<int> dijkstra(int, int) const;
	// Returns the path from "start" to "finish".
	// The first value in the returned list should be start.
	// The last value in the returned list should be finish.
};
