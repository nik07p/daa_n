#include <iostream>
#include <vector>
#include <climits>

using namespace std;


struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    // Print the distance to all vertices
    cout << "Vertex Distance from Source:" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << " \t\t" << "INF" << endl;
        else
            cout << i << " \t\t" << dist[i] << endl;
    }
}

int main() {
    int V, E; // V -> Number of vertices, E -> Number of edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter the source, destination and weight of each edge:" << endl;
    for (int i = 0; i < E; i++) {
      
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    bellmanFord(V, E, edges, src);

    return 0;
}

/*
Enter the number of vertices and edges: 4 5
Enter the source, destination and weight of each edge:
0 1 5
0 2 4
1 2 -3
2 3 2
1 3 6
Enter the source vertex: 0
Vertex Distance from Source:
0               0
1               5
2               2
3               4
*/