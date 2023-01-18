#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// This class represents a directed graph using an adjacency list representation
class Graph
{
    int numVertices;             // Number of vertices in the graph
    vector<vector<int>> adjList; // Adjacency list

public:
    Graph(int numVertices) : numVertices(numVertices), adjList(numVertices) {}

    // Add an edge from vertex u to vertex v
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    // Perform a breadth-first search starting from vertex v
    void BFS(int v)
    {
        vector<bool> visited(numVertices, false); // Keep track of visited vertices
        queue<int> q;                             // Queue to hold the vertices to be visited

        // Mark the current vertex as visited and enqueue it
        visited[v] = true;
        q.push(v);

        while (!q.empty())
        {
            // Dequeue a vertex from the queue and print it
            int u = q.front();
            q.pop();
            cout << u << " ";

            // Enqueue all the unvisited vertices adjacent to u
            for (int v : adjList[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};

int main()
{
    // Create a graph with 5 vertices
    Graph g(5);

    // Add some edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // Perform a BFS starting from vertex 2
    g.BFS(2);

    return 0;
}
