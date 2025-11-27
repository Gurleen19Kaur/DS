#include <iostream>
using namespace std;

int findSet(int parent[], int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unionSet(int parent[], int a, int b) {
    parent[a] = b;
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    int edges[100][3]; // u v w
    cout << "Enter edges (u v weight) sorted by weight:\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    int parent[100];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "\nKruskal MST:\n";
    int count = 0;

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        int setU = findSet(parent, u);
        int setV = findSet(parent, v);

        if (setU != setV) {
            cout << u << " - " << v << " (" << w << ")\n";
            unionSet(parent, setU, setV);
            count++;
            if (count == V - 1) break;
        }
    }
}
