#include <iostream>
using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
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
    cout << "Enter start vertex for BFS: ";
    cin >> start;

    int visited[100] = {0};
    int q[100], front = 0, rear = 0;

    visited[start] = 1;
    q[rear++] = start;

    cout << "BFS: ";

    while (front < rear) {
        int u = q[front++];
        cout << u << " ";

        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = 1;
                q[rear++] = v;
            }
        }
    }
}

