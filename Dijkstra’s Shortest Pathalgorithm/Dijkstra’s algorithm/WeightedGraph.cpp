#include "weightedgraph.h"

void WeightedGraph::copy(const WeightedGraph& aGraph) {                 // Copies a graph (requires a for loop!)
	mVertices = aGraph.mVertices;
	mGraph = new int[mVertices * mVertices];

	for (int i = 0; i < (mVertices * mVertices); i++) {
		mGraph[i] = aGraph.mGraph[i];
	}
}

void WeightedGraph::checkForVertexInRange(int v) const {   // Checks for a vertex in range
	if (v > mVertices * mVertices || v < 0) {
		throw std::invalid_argument("Index out of bounds");
	}
}

WeightedGraph::WeightedGraph(int m) {
	mVertices = m;                      // Set mVertices = m DONE
	mGraph = new int[m * m];           	// Builds a blank matrix that is m * m
	for (int i = 0; i < (m * m); i++) {   // Sets all elements of mGraph to 0.
		mGraph[i] = 0;
	}
}										// Builds a blank matrix that is m * m
										// Set mVertices = m DONE

WeightedGraph::~WeightedGraph() {
	delete[] mGraph;                     // Destructor
}


WeightedGraph::WeightedGraph(const WeightedGraph& aWeightedGraph) {     // Copy Constructor
	copy(aWeightedGraph);
}

WeightedGraph&  WeightedGraph:: operator=(const WeightedGraph& aWeightedGraph) {
	// Sets passed graph equal to this graph.
	// 1. Deletes internal mGraph array
	// 2. Copies passed graph to this graph

	if (this != &aWeightedGraph) {
		delete[] mGraph;
		copy(aWeightedGraph);
	}
	return *this;
}

bool WeightedGraph::operator==(const WeightedGraph&) const {
	for (int i = 0; i < mVertices; i++) {
		for (int j = 0; j < mVertices; j++) {
			if (get(i, j) != get(j, i))
				return false;
		}
	}
	return true;
}

int WeightedGraph::GetNumVertices() const {              // Returns mVertices
	return mVertices;
}

int WeightedGraph::GetNumEdges() const {              // Counts and returns the number of
													  // cells in mGraph > 0 (requires a for loop!)
	int i = 0, count = 0;
	while (i < mVertices) {
		if (mGraph[i] > 0) {
			count++;
		}
		i++;
	}
	return count;
}

void WeightedGraph::set(int i, int j, int weight) {
	checkForVertexInRange(i);
	checkForVertexInRange(j);
	int index = i* mVertices + j;
	mGraph[index] = weight;

}
// Sets index i,j to weight
// First param: i
// Second param: j
// Third param: weight
// Check to make sure that i and j are a vertex in range

void WeightedGraph::set(int i, int j) {
	int weight = 1;
	set(i, j, weight);
}

// Calls "set(i,j,weight)" with weight=1
int WeightedGraph::get(int i, int j) const {

	//(need to do precondition checks)
	checkForVertexInRange(i);
	checkForVertexInRange(j);
	int index = i * mVertices + j;
	return mGraph[index];

}
// Returns mGraph at cell (i,j)
// Check to make sure that i and j are a vertex in range

bool  WeightedGraph::isSymmetric() const {
	for (int i = 0; i < mVertices; i++) {
		for (int j = 0; j < mVertices; j++) {
			if (get(i, j) == get(j, i))
				return true;
		}
	}
	return false;  // Returns true if every elements at (i,j) is identical to (j,i)
}

bool  WeightedGraph::isAntisymmetric() const {

	for (int i = 0; i < mVertices; i++) {
		for (int j = 0; j < mVertices; j++) {
			if (i != j) {
				if (get(i, j) == 1 && get(j, i) == 1) {
					return false;
				}

			}

		}
	}
	return true;
}
// Returns true if element at (i,j) is 1 and element (j,i)
// is 0 (provided that i != j)
// Each of these methods require a for loop
WeightedGraph  WeightedGraph::transpose() const {
	WeightedGraph tGraph(mVertices);

	for (int i = 0; i < mVertices; i++) {
		for (int j = 0; j < mVertices; j++) {
			tGraph.set(i, j, get(j, i));
		}
	}

	return tGraph;
}
// Builds a new matrix which is transpose of this matrix

bool  WeightedGraph::isReflexive() const {
	for (int i = 0; i < mVertices; i++) {
		if (get(i, i) != 1) {
			return false;
		}
	}
	return true;
}
// Returns true if all elements along the diagonal are > 0

void  WeightedGraph::visualize() const {
	for (int i = 0; i < mVertices; i++) {
		for (int j = 0; j < mVertices; j++) {
			std::cout << get(i, j);
		}
		std::cout << std::endl;
	}
}
// Visualizes the matrix