#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Unique Paths (Grid)
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

// Minimum Path Sum
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            else if (i == 0) grid[i][j] += grid[i][j-1];
            else if (j == 0) grid[i][j] += grid[i-1][j];
            else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[m-1][n-1];
}

int main() {
    cout << "Unique Paths (3x7): " << uniquePaths(3, 7) << endl;
    
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << "Min Path Sum: " << minPathSum(grid) << endl;
    return 0;
}
