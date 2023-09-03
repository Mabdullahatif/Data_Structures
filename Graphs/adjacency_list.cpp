/*
    This C++ code demonstrates the implementation of Depth-First Search (DFS) and Breadth-First Search (BFS)
    algorithms on a directed graph using adjacency lists.

    The code defines a class "Graph" that allows you to create a directed graph, connect nodes, and perform DFS
    and BFS traversals on the graph.

    1. The "Graph" class: It represents a directed graph with a given number of vertices. It maintains an adjacency
       list for each vertex, which stores the neighboring vertices that can be reached from a particular vertex.
       The class also maintains an array of "visited" flags to keep track of visited vertices during traversals.

    2. void connectNodes(int a, int b): This method connects two nodes in the graph, creating a directed edge
       from node 'a' to node 'b'.

    3. void resetVisited(): Resets the "visited" flags for all vertices to mark them as unvisited.

    4. void DFS(int start): Performs a Depth-First Search traversal starting from the specified vertex 'start'.
       It calls a recursive DFSUtil function.

    5. void DFSUtil(int start): A recursive helper function for DFS that prints the visited vertices in DFS order.

    6. void BFS(int start): Performs a Breadth-First Search traversal starting from the specified vertex 'start'.
       It uses a queue to explore vertices in a breadth-first manner.

    In the "main" function, a graph is created with four vertices, and directed edges are established between them.
    The code then demonstrates DFS and BFS starting from vertex 2.

    Example:
    - Given the graph connections:
      0 -> 1
      0 -> 2
      1 -> 2
      2 -> 0
      2 -> 3
      3 -> 3

    Output:
    DFS starting from vertex 2: 2 0 1 3
    BFS starting from vertex 2: 2 0 3 1
*/

#include <iostream>
#include <list>
#include <queue> // Added for BFS using std::queue

using namespace std;

class Graph {
    list<int>* AdjList;
    bool* visited;
    int vertexes;

public:
    Graph(int count) : vertexes(count) {
        AdjList = new list<int>[vertexes];
        visited = new bool[vertexes];

        // Initially, all the vertices should be unvisited
        for (int i = 0; i < vertexes; i++)
            visited[i] = false;
    }

    void connectNodes(int a, int b) {
        AdjList[a].push_back(b); // Directed graph
    }

    void resetVisited() {
        for (int i = 0; i < vertexes; i++)
            visited[i] = false;
    }

    void DFS(int start) {
        resetVisited();
        DFSUtil(start);
    }

    void BFS(int start) {
        resetVisited();
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            start = q.front();
            cout << start << " ";
            q.pop();

            for (auto x : AdjList[start])
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
        }
    }

    void DFSUtil(int start) {
        cout << start << " ";
        visited[start] = true;

        for (auto x : AdjList[start]) {
            if (!visited[x])
                DFSUtil(x);
        }
    }

    ~Graph() {
        delete[] AdjList;
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
