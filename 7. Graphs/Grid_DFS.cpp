#include <iostream>
#include <vector>

using namespace std;

// DFS on a grid: Count connected components (Number of Islands) - 4 directions
void dfsFill(int r, int c, vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1) return;
    grid[r][c] = -1; // mark visited
    const int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    for (auto &d : dirs) dfsFill(r + d[0], c + d[1], grid);
}

int numIslands(vector<vector<int>> grid) {
    if (grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                ++count;
                dfsFill(i, j, grid);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> grid1 = {
        {1,1,0,0,0},
        {1,1,0,0,1},
        {0,0,0,1,1},
        {0,0,0,0,0},
        {0,0,0,0,1}
    };

    vector<vector<int>> grid2 = {{1,1,1},{0,1,0},{1,1,1}};

    cout << "Grid DFS (Number of Islands) examples" << endl;
    cout << "grid1 -> " << numIslands(grid1) << " (expected 3)" << endl;
    cout << "grid2 -> " << numIslands(grid2) << " (expected 1)" << endl;
    return 0;
}
