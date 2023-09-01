/*
This C++ code demonstrates the implementation of Depth-First Search (DFS) on a graph. DFS is a fundamental graph traversal algorithm used to explore all vertices and edges of a graph in a systematic manner.

In this code:

1. We define a `Graph` class that allows you to create a graph with a specified number of vertices.
2. The `addEdge` method is used to add edges between vertices in the graph.
3. The `DFS` method performs a depth-first traversal starting from a given vertex. It uses a stack data structure to keep track of the vertices to be visited next.
4. A vector `visited` is used to mark vertices as visited to avoid revisiting them.
5. The code demonstrates DFS starting from different vertices, showing the traversal order.

Example:
Suppose we have a graph with three vertices (0, 1, 2) and the following edges:
- Edge (0, 1)
- Edge (0, 2)
- Edge (1, 2)
- Edge (2, 0)

The code will perform DFS starting from each vertex:
- DFS starting from vertex 0: 0 -> 1 -> 2
- DFS starting from vertex 1: 1 -> 2 -> 0
- DFS starting from vertex 2: 2 -> 0 -> 1

This code is a basic illustration of how DFS can be implemented to explore a graph's vertices and edges.

To compile and run the code, use a C++ compiler and provide the appropriate filename.
*/
#include <iostream>
#include <stack>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int vertex;
    list<int> *adjacent;

public:
    Graph(int size) {
        vertex = size;
        adjacent = new list<int>[size];
    }

    // Function to add an edge to the graph
    void addEdge(int source, int destination) {
        adjacent[source].push_back(destination);
    }

    // Depth-First Search starting from a given vertex
    void DFS(int startVertex) {
        vector<bool> visited(vertex, false);
        stack<int> stack_check;

        stack_check.push(startVertex);
        visited[startVertex] = true;

        cout << "Depth-First Traversal starting from vertex " << startVertex << ": ";
        
        while (!stack_check.empty()) {
            int currentVertex = stack_check.top();
            stack_check.pop();
            
            cout << currentVertex << " ";

            for (int neighbor : adjacent[currentVertex]) {
                if (!visited[neighbor]) {
                    stack_check.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        
        cout << endl;
    }
};

int main() {
    Graph obj(3);
    
    // Adding edges to the graph
    obj.addEdge(0, 1);
    obj.addEdge(0, 2);
    obj.addEdge(1, 2);
    obj.addEdge(2, 0);

    // Perform DFS starting from different vertices
    obj.DFS(0); // Starting from vertex 0
    obj.DFS(1); // Starting from vertex 1
    obj.DFS(2); // Starting from vertex 2

    return 0;
}
