#include <iostream>
using namespace std;

#define INF 999999

int minDist(int dist[], int vis[], int N) {
    int minVal = INF, idx = -1;
    for (int i = 1; i <= N; i++)
        if (!vis[i] && dist[i] < minVal) {
            minVal = dist[i];
            idx = i;
        }
    return idx;
}

int main() {
    int N, E, K;
    cin >> N >> E >> K;

    int adj[101][101];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    int dist[101], vis[101] = {0};
    for (int i = 1; i <= N; i++)
        dist[i] = INF;

    dist[K] = 0;

    for (int i = 1; i <= N; i++) {
        int u = minDist(dist, vis, N);
        if (u == -1) break;
        vis[u] = 1;

        for (int v = 1; v <= N; v++)
            if (adj[u][v] && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) {
            cout << -1;
            return 0;
        }
        if (dist[i] > ans)
            ans = dist[i];
    }

    cout << ans;
    return 0;
}
