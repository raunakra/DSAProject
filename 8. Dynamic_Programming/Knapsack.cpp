#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0/1 Knapsack Problem
// Problem: Given weights and values of n items, put these items in a knapsack 
// of capacity W to get the maximum total value in the knapsack.
// Each item can be included at most once (0/1 choice).
//
// Example: weights = [10, 20, 30], values = [60, 100, 120], capacity = 50
// Output: 220 (items with weight 20 and 30)
//
// Time Complexity: O(n*W), Space Complexity: O(n*W)
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i-1] <= w) {
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    
    vector<int> v(val, val + n);
    vector<int> w(wt, wt + n);
    
    cout << "Max Value: " << knapsack(W, w, v, n) << endl;
    return 0;
}
