#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Longest Common Subsequence
// Problem: Given two strings text1 and text2, return the length of their longest common subsequence.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements
// without changing the order of the remaining elements.
// Example: text1 = "abcde", text2 = "ace" → Output: 3 (The LCS is "ace")
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

// Longest Increasing Subsequence
// Problem: Given an integer array nums, return the length of the longest strictly increasing subsequence.
// A subsequence is a sequence that can be derived from an array by deleting some or no elements
// without changing the order of the remaining elements.
// Example: nums = [10,9,2,5,3,7,101,18] → Output: 4 (The LIS is [2,3,7,101])
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> dp(nums.size(), 1);
    int maxLen = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

int main() {
    cout << "LCS: " << longestCommonSubsequence("abcde", "ace") << endl;
    
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << "LIS: " << lengthOfLIS(nums) << endl;
    return 0;
}
