#include <iostream>
using namespace std;

void dfs(int adj[100][100], int V, int u, int visited[]) {
    visited[u] = 1;

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(adj, V, v, visited);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    int adj[100][100] = {0};
    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    int visited[100] = {0};
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {   
            dfs(adj, V, i, visited);
            count++;
        }
    }

    cout << "Number of connected components = " << count;
    return 0;
}
