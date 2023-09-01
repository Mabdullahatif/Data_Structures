/*
This C++ code solves the "Visit Every City" problem using Depth-First Search (DFS) on a directed graph. Given a graph with cities (vertices) and roads (edges), the goal is to find a path that visits every city exactly once while using a limited number of flights.

In this code:

1. We define a `Graph` class to represent the directed graph, where each city is a vertex, and roads between cities are edges.

2. The `addEdge` method is used to add directed edges to the graph.

3. The `visitEveryCity` function uses DFS to explore paths starting from each city, taking flights when needed, to visit every city exactly once. It maintains a list of visited cities and keeps track of flights taken.

4. The code reads the number of cities (`vertices`), roads (`roads`), and flights (`flights`) from the input. It then reads the road connections and constructs the graph.

5. The `visitEveryCity` function is called with the graph and maximum allowed flights (`flights`). If a valid path is found, it prints the path, or it prints -1 if no valid path exists.

6. Assertions are used to ensure that the input values are non-negative.

Example:
Suppose there are 5 cities (vertices), 6 roads, and 2 flights allowed. The code reads the road connections and constructs the graph:

Input:
5 6 2
1 2
2 3
3 4
4 5
5 1
1 3

Output (a valid path visiting every city exactly once):
1 2 3 4 5

Output (if no valid path exists):
-1

This code provides a solution to the problem of visiting every city exactly once while using a limited number of flights.

To compile and run the code, use a C++ compiler and provide the appropriate filename.
*/
#include <iostream>
#include <stack>
#include <list>
#include <unordered_map>
#include <cassert>

using namespace std;

class Graph {
public:
    int vertex;
    list<int> *adjacent;

    Graph(int size) {
        adjacent = new list<int>[size];
        vertex = size;
    }

    void addEdge(int source, int destination) {
        adjacent[source].push_back(destination);
    }
};

bool visitEveryCity(Graph& graph, int maxFlights, int flightsTaken, int nodesVisited, list<int>& path, int start, unordered_map<int, bool>& isChecked) {
    if (flightsTaken > maxFlights) {
        return false;
    }
    
    stack<int> S;

    S.push(start);
    path.push_back(start + 1);
    isChecked[start] = true;
    nodesVisited++;

    while (!S.empty()) {
        int i = S.top();
        auto it = graph.adjacent[i].begin();
        while (it != graph.adjacent[i].end() && isChecked[*it] == true) {
            it++;
        }

        if (it == graph.adjacent[i].end()) {
            S.pop();
        } else {
            S.push(*it);
            path.push_back(*it + 1);
            isChecked[*it] = true;
            nodesVisited++;
        }
    }

    if (nodesVisited < graph.vertex) {
        start = -1;
        for (int i = 0; i < graph.vertex && start == -1; i++) {
            if (!isChecked[i]) {
                start = i;
            }
        }
        return visitEveryCity(graph, maxFlights, flightsTaken + 1, nodesVisited, path, start, isChecked);
    }

    return true;
}

void visitEveryCity(Graph& graph, int maxFlights) {
    list<int> path;
    unordered_map<int, bool> isChecked;

    for (int vertex_iterator = 0; vertex_iterator < graph.vertex; vertex_iterator++) {
        isChecked[vertex_iterator] = false;
    }

    if (visitEveryCity(graph, maxFlights, 0, 0, path, 0, isChecked)) {
        for (auto val : path) {
            cout << val << " ";
        }
    } else {
        cout << -1;
    }
}

int main() {
    int vertices, roads, flights;
    int c1, c2;
    cin >> vertices >> roads >> flights;
    assert(vertices > 0);
    assert(roads >= 0);
    assert(flights >= 0);

    Graph graph(vertices);

    for (int i = 0; i < roads; i++) {
        cin >> c1 >> c2;
        graph.addEdge(c1 - 1, c2 - 1);
    }

    visitEveryCity(graph, flights);
    return 0;
}
