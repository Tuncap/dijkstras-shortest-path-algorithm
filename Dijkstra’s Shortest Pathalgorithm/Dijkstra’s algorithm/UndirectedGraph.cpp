#include "UndirectedGraph.h"

UndirectedGraph::UndirectedGraph(int mVertices) : WeightedGraph(mVertices)
{
	// No need to do something here,
	// parent constructor will be called from
	// the initialization list
}

void UndirectedGraph::set(int i, int j, int weight)
{
	// Let's reuse parent's methods
	WeightedGraph::set(i, j, weight);
	WeightedGraph::set(j, i, weight);
}

void UndirectedGraph::set(int i, int j)
{
	// Reuse existing method
	set(i, j, 1);
}

LinkedList<int> UndirectedGraph::dijkstra(int start, int finish) const
{
	// Create an integer array of length Number of Vertices named distances
	int* distances = new int[GetNumVertices()];

	// Create an integer array of length Number of Vertices named previous
	int* previous = new int[GetNumVertices()];

	// Create a Boolean array of length Number of Vertices named unreached
	bool* unreached = new bool[GetNumVertices()];

	// Set all of distances to be INT MAX
	for (int i = 0; i < GetNumVertices(); i++) {
		distances[i] = INT_MAX;
	}

	// Set all of previous to be -1
	for (int i = 0; i < GetNumVertices(); i++) {
		previous[i] = -1;
	}

	// Set all of unreached to be true
	for (int i = 0; i < GetNumVertices(); i++) {
		unreached[i] = true;
	}

	// Set distance[start] to be 0
	distances[start] = 0;

	// Create an integer unreachedCount set to Number of Vertices
	int unreachedCount = GetNumVertices();

	// While unreachedCount greater than 0
	while (unreachedCount > 0) {
		// Find the index position of the smallest element in distances
		// where the matching index of unreached is also true.
		// This index position is named vertex.
		int vertex = -1;
		int value = INT_MAX;
		for (int i = 0; i < GetNumVertices(); i++) {
			if ((distances[i] < value) && (unreached[i] == true)) {
				value = distances[i];
				vertex = i;
			}
		}

		// Set unreached[vertex] to be false.
		unreached[vertex] = false;

		// Decrement unreachedCount by 1.
		unreachedCount--;

		// For each vertex v which is a neighbor to to vertex.
		for (int v = 0; v < GetNumVertices(); v++) {
			// If the weight at(vertex, v) is greater than 0 and less than distances[vertex]...
			if ((get(vertex, v) > 0) && (distances[vertex] + get(vertex, v) < distances[v])) {
				//	Update distances[v] to be the weight at(vertex, v).
				distances[v] = distances[vertex] + get(vertex, v);
				//	Update previous[v] to be vertex.
				previous[v] = vertex;
			}
		}
	}

	// Create a linked list of ints.
	LinkedList<int> route = LinkedList<int>();

	// set a int vertex to finish
	int vertex = finish; // N.B! This is other vertex variable with the same name like in while-loop

	// while vertex does not equal - 1:
	while (vertex != -1) {
		// push vertex onto the front of the linked list
		route.push_front(vertex);
		// set vertex as previous[vertex]
		vertex = previous[vertex];
	}

	// Delete all of your dynamically created arrays
	delete[] distances;
	delete[] previous;
	delete[] unreached;

	// Return the linked list
	return route;
}
