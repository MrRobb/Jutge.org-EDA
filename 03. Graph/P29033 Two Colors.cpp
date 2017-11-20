//
//  P29033 Two Colors.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 20/11/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph
{
private:
	
	// number of vertices
	int n;
	
	// pointer -> array containing adjacency lists
	list<int> *adj;
	
	// DFS Search
	void DFS(int v, vector<bool> &visited) {
		visited[v] = true;
		for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
			if (not visited[(*i)]) {
				DFS((*i), visited);
			}
		}
	}
	
public:
	
	// Constructor
	Graph(int n)
	{
		this->n = n;
		adj = new list<int> [n];
	}
	
	// Add edge
	void addEdge(int v, int w) {
		adj[v].push_back(w);
		adj[w].push_back(v);
	}
	
	// Bipartite
	bool isBipartite(Graph* const &g, int v, vector<bool> &visited, vector<int> &color)
	{
		// For every adjacent vertex
		for (int w : g->adj[v])
		{
			if (not visited[w])
			{
				visited[w] = true;
				color[w] = not color[v];
				
				if (not isBipartite(g, w, visited, color))
					return false;
			}
			else if (color[v] == color[w])
				return false;
		}
		return true;
	}
};


int main() {
	int n;
	int m;
	
	while (cin >> n >> m)
	{
		// Read
		Graph *g = new Graph(n);
		for (int i = 0; i < m; ++i) {
			int v; cin >> v;
			int w; cin >> w;
			g->addEdge(v, w);
		}
		
		// Compute
		vector<bool> visited(n, false);
		vector<int> color(n);
		bool bipartite = true;
		
		// Check all connected components
		for (int i = 0; i < n and bipartite; i++) {
			if (not visited[i]) {
				visited[i] = true;
				color[i] = 0;
				bipartite = g->isBipartite(g, i, visited, color);
			}
		}
		
		// Print
		cout << (bipartite ? "yes" : "no") << endl;
	}
}
 
