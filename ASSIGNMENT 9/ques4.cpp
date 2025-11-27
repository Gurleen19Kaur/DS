#include <iostream>
using namespace std;

#define INF 999999

int minDist(int dist[], int vis[], int V) {
    int min = INF, idx = -1;
    for (int i = 0; i < V; i++) {
        if (!vis[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int adj[100][100];
    cout << "Enter weighted adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> adj[i][j];

    int start;
    cout << "Enter start node: ";
    cin >> start;

    int dist[100], vis[100] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[start] = 0;

    for (int i = 0; i < V; i++) {
        int u = minDist(dist, vis, V);
        vis[u] = 1;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] > 0 && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
        }
    }

    cout << "\nDijkstra Shortest Distances:\n";
    for (int i = 0; i < V; i++)
        cout << start << " → " << i << " = " << dist[i] << "\n";
}
