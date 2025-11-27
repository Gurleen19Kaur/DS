#include <iostream>
using namespace std;

void dfs(int grid[100][100], int vis[100][100], int r, int c, int m, int n) {
    if (r < 0 || c < 0 || r >= m || c >= n) return;
    if (grid[r][c] == 0 || vis[r][c]) return;

    vis[r][c] = 1;

    dfs(grid, vis, r + 1, c, m, n);
    dfs(grid, vis, r - 1, c, m, n);
    dfs(grid, vis, r, c + 1, m, n);
    dfs(grid, vis, r, c - 1, m, n);
}

int main() {
    int m, n;
    cin >> m >> n;

    int grid[100][100], vis[100][100];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            vis[i][j] = 0;
        }

    int count = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1 && !vis[i][j]) {
                dfs(grid, vis, i, j, m, n);
                count++;
            }

    cout << count;
    return 0;
}
