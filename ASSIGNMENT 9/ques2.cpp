#include <iostream>
using namespace std;

void dfs(int adj[100][100], int V, int u, int visited[]) {
    visited[u] = 1;
    cout << u << " ";

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(adj, V, v, visited);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    int adj[100][100] = {0};

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    int visited[100] = {0};
    cout << "DFS: ";
    dfs(adj, V, start, visited);
}
