// 1971. Find if path exists

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
private:
    list<int> *l;

    // Function to add an edge between two nodes
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // Depth-First Search function to check if a path exists
    bool DFS(vector<bool>& vis, int source, int destination) {
        // If the current node is the destination, return true
        if (source == destination) {
            return true;
        }

        // Mark the current node as visited
        vis[source] = true;

        // Iterate through all adjacent nodes
        for (int neighbor : l[source]) {
            // If the adjacent node has not been visited
            if (!vis[neighbor]) {
                // Recursively call DFS
                if (DFS(vis, neighbor, destination)) {
                    return true;
                }
            }
        }

        // If no path is found through any adjacent nodes, return false
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Initialize the adjacency list
        l = new list<int>[n];

        // Add all edges to the adjacency list
        for (int i = 0; i < edges.size(); i++) {
            addEdge(edges[i][0], edges[i][1]);
        }

        // Initialize the visited array
        vector<bool> vis(n, false);

        // Call the DFS function to check for a valid path
        return DFS(vis, source, destination);
    }
};