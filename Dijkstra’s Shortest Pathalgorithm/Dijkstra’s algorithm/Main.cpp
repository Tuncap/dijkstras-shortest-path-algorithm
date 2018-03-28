#include <iostream>
#include "UndirectedGraph.h"
#include "linkedlist.hpp"
#include <vector>

using namespace std;

int main(int argc, char* argv) {

	cout << "Number of vertices in our matrix :";
	int matrix_size;
	cin >> matrix_size;
	UndirectedGraph graph(matrix_size);

	vector<char> places;
	for (int i = 0; i < matrix_size; i++) {
		cout << "Enter the name of place " << i << " :";
		char place;
		cin >> place;
		places.push_back(place);
	}

	cout << "Number of edges in our matrix :";
	int edges_count;
	cin >> edges_count;

	for (int i = 0; i < edges_count; i++) {
		cout << "Enter a starting vertex number : ";
		int svn = 0;
		cin >> svn;
		cout << "Enter a ending vertex number : ";
		int evn = 0;
		cin >> evn;
		cout << "Enter a weight : ";
		int weight = 0;
		cin >> weight;

		graph.set(svn, evn, weight);
	}

	cout << "Enter the starting location vertex number : ";
	int start = 0;
	cin >> start;

	cout << "Enter the finishing location vertex number : ";
	int finishing = 0;
	cin >> finishing;

	// Processing
	LinkedList<int> route = graph.dijkstra(start, finishing);
	
	for (int i = 0; i < matrix_size; i++)
		cout << i << " : " << places[i] << endl;
		
	cout << "Original Graph." << endl;
	graph.visualize();
	
	cout << "Path from " << places[start] << " to " << places[finishing] << "." << endl;
	int route_distance = 0;
	for (int i = 0; i < route.size(); i++) {
		cout << i + 1 << ": " << places[route.get(i)] << endl;
		if (i != 0) {
			route_distance += graph.get(route.get(i), route.get(i - 1));
		}
	}

	cout << "Distance : " << route_distance << endl;
	cout << "Done." << endl;

	system("pause");
	return 0;
}