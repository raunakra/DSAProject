#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS on a grid: Shortest Path in a Binary Matrix (8-directional)
int shortestPathBinaryMatrix(vector<vector<int>> grid) {
    int n = grid.size();
    if (n == 0) return -1;
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

    const int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    queue<pair<int,int>> q;
    q.push({0,0});
    grid[0][0] = 1; // visited
    int steps = 1;

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [r,c] = q.front(); q.pop();
            if (r == n-1 && c == n-1) return steps;

            for (auto &d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >=0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; // mark visited
                    q.push({nr,nc});
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    // Example usages
    vector<vector<int>> g1 = {{0,1},{1,0}}; // shortest path is 2
    vector<vector<int>> g2 = {{0,0,0},{1,1,0},{1,1,0}}; // shortest path is 4

    cout << "Grid BFS (shortest path) examples" << endl;
    cout << "g1 -> " << shortestPathBinaryMatrix(g1) << " (expected 2)" << endl;
    cout << "g2 -> " << shortestPathBinaryMatrix(g2) << " (expected 4)" << endl;
    return 0;
}
