#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS on Matrix (e.g., Number of Islands or Shortest Path)
// Directions array for moving up, down, left, right
const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1; // Mark as visited by changing value
    
    int pathLength = 1;
    
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == n - 1 && c == n - 1) return pathLength;
            
            // Note: This example uses 8 directions for diagonal movement as well, 
            // but standard BFS often uses 4. Adjust as needed.
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;
                    int nr = r + i;
                    int nc = c + j;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        q.push({nr, nc});
                        grid[nr][nc] = 1; // Mark visited
                    }
                }
            }
        }
        pathLength++;
    }
    return -1;
}

int main() {
    vector<vector<int>> grid = {{0,1},{1,0}};
    cout << "Shortest Path: " << shortestPathBinaryMatrix(grid) << endl;
    return 0;
}
