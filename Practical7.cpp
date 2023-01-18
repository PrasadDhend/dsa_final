#include <iostream>
#include <vector>
using namespace std;

// Graph class representing a directed graph using an adjacency list
class Graph
{
public:
    // Constructor to create a graph with 'n' vertices
    Graph(int n) : adj_list_(n) {}

    // Add an edge from vertex 'u' to vertex 'v'
    void AddEdge(int u, int v) { adj_list_[u].push_back(v); }

    // Perform a depth-first search on the graph, starting at vertex 's'
    void DFS(int s)
    {
        // Mark all the vertices as not visited
        vector<bool> visited(adj_list_.size(), false);

        // Call the recursive helper function to print DFS traversal
        DFSUtil(s, visited);
    }

private:
    // Recursive function for DFS traversal
    void DFSUtil(int v, vector<bool> &visited)
    {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int adj_v : adj_list_[v])
        {
            if (!visited[adj_v])
            {
                DFSUtil(adj_v, visited);
            }
        }
    }

    // Adjacency list representation of the graph
    vector<vector<int>> adj_list_;
};

int main(void)
{
    // Create a graph with 4 vertices
    Graph g(4);

    // Add edges to the graph
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);

    // Perform a depth-first search starting at vertex 2
    cout << "DFS starting at vertex 2: ";
    g.DFS(2);
    cout << endl;

    return 0;
}
