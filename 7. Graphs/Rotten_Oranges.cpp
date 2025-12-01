#include <bits/stdc++.h>
using namespace std;

// Rotting Oranges (multi-source BFS)
// Time: O(R * C) where R = rows, C = cols (each cell visited at most once)
// Space: O(R * C) for the queue + visited state in worst case
// Given a grid of 0 = empty, 1 = fresh orange, 2 = rotten orange — return the minimum
// number of minutes needed until no fresh orange remains, or -1 if impossible.

int orangesRotting(vector<vector<int>>& grid) {
    int R = grid.size();
    if (R == 0) return 0;
    int C = grid[0].size();

    queue<pair<int,int>> q;
    int fresh = 0;

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (grid[r][c] == 2) q.push({r,c});
            else if (grid[r][c] == 1) fresh++;
        }
    }

    if (fresh == 0) return 0; // no fresh oranges

    int minutes = 0;
    vector<int> dr = {1,-1,0,0};
    vector<int> dc = {0,0,1,-1};

    while (!q.empty()) {
        int sz = q.size();
        bool turned = false;
        for (int i = 0; i < sz; ++i) {
            auto [r,c] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // becomes rotten
                    q.push({nr,nc});
                    fresh--;
                    turned = true;
                }
            }
        }
        if (turned) minutes++; // only count minute if at least one fresh turned
    }

    return fresh == 0 ? minutes : -1;
}

int main() {
    // Example 1: expected 4
    vector<vector<int>> g1 = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout << "Example 1 minutes: " << orangesRotting(g1) << '\n';

    // Example 2: expected -1 (isolated fresh orange)
    vector<vector<int>> g2 = {
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };
    cout << "Example 2 minutes: " << orangesRotting(g2) << '\n';

    // Example 3: expected 0 (no fresh oranges)
    vector<vector<int>> g3 = {
        {0,2}
    };
    cout << "Example 3 minutes: " << orangesRotting(g3) << '\n';

    return 0;
}
