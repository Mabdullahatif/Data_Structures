/*
    This C++ code demonstrates the implementation of Depth-First Search (DFS) and Breadth-First Search (BFS)
    algorithms on a graph represented as an adjacency matrix.

    The code defines a class "Graph" that allows you to create an adjacency matrix-based graph, connect nodes,
    and perform DFS and BFS traversals on the graph.

    1. The "Graph" class: It represents a graph using an adjacency matrix. The matrix stores information about
       the connections between vertices. The class also maintains an array of "visited" flags to keep track
       of visited vertices during traversals.

    2. void connectNodes(int a, int b): This method connects two nodes in the graph by setting the corresponding
       entry in the adjacency matrix to 1, indicating an edge between nodes 'a' and 'b'.

    3. void resetVisited(): Resets the "visited" flags for all vertices to mark them as unvisited.

    4. void DFS(int start): Performs a Depth-First Search traversal starting from the specified vertex 'start'.
       It uses a recursive approach to explore connected vertices in a depth-first manner.

    5. void BFS(int start): Performs a Breadth-First Search traversal starting from the specified vertex 'start'.
       It uses a queue to explore vertices in a breadth-first manner.

    In the "main" function, a graph is created with four vertices, and edges are established between them
    based on the input. The code then demonstrates DFS and BFS starting from vertex 2.

    Example:
    - Given the graph connections (edges):
      0 - 1
      | /
      2 - 3

    Output:
    DFS starting from vertex 2: 2 0 1 3
    BFS starting from vertex 2: 2 0 3 1
*/
#include <iostream>
#include <list>

using namespace std;

class Graph {
    int** matrix;
    int vertices; // Changed bool* to int* for visited array
    bool* visited;

public:
    Graph(int v) : vertices(v) {
        matrix = new int*[v]; // Adjacency Matrix
        for (int i = 0; i < v; i++)
            matrix[i] = new int[v];

        visited = new bool[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = false;
    }

    void connectNodes(int a, int b) {
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }

    void resetVisited() {
        for (int i = 0; i < vertices; i++)
            visited[i] = false;
    }

    void DFS(int start) {
        cout << start << " ";
        visited[start] = true;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && matrix[start][i] == 1) {
                DFS(i);
            }
        }
    }

    void BFS(int start) {
        resetVisited();
        list<int> q;
        q.push_back(start);

        while (!q.empty()) {
            int start = q.front();
            cout << start << " ";
            visited[start] = true;
            q.pop_front();

            for (int i = 0; i < vertices; i++) {
                if (!visited[i] && matrix[start][i] == 1) {
                    q.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++)
            delete[] matrix[i];
        delete[] matrix;
        delete[] visited;
    }
};

int main() {
    Graph g(4);
    g.connectNodes(0, 1);
    g.connectNodes(0, 2);
    g.connectNodes(1, 2);
    g.connectNodes(2, 0);
    g.connectNodes(2, 3);
    g.connectNodes(3, 3);

    cout << "DFS starting from vertex 2: ";
    g.DFS(2);
    cout << endl;

    cout << "BFS starting from vertex 2: ";
    g.BFS(2);

    return 0;
}
