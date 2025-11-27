#include <iostream>
using namespace std;

#define INF 999999

int main() {
    int m, n;
    cin >> m >> n;

    int grid[100][100];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int dist[100][100], vis[100][100];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
            vis[i][j] = 0;
        }

    dist[0][0] = grid[0][0];

    while (true) {
        int r = -1, c = -1;
        int minVal = INF;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!vis[i][j] && dist[i][j] < minVal) {
                    minVal = dist[i][j];
                    r = i;
                    c = j;
                }

        if (r == -1) break;

        vis[r][c] = 1;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n)
                if (dist[r][c] + grid[nr][nc] < dist[nr][nc])
                    dist[nr][nc] = dist[r][c] + grid[nr][nc];
        }
    }

    cout << dist[m-1][n-1];
    return 0;
}

