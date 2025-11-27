#include <iostream>
using namespace std;

#define INF 999999

int minKey(int key[], int mst[], int V) {
    int min = INF, index = -1;
    for (int i = 0; i < V; i++) {
        if (!mst[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int adj[100][100];
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> adj[i][j];

    int key[100], mst[100], parent[100];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mst[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mst, V);
        mst[u] = 1;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !mst[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nPrim's MST:\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " (" << adj[i][parent[i]] << ")\n";
}

