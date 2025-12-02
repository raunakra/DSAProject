#include <bits/stdc++.h>
using namespace std;

// Amazon & Salesforce Frequently Asked Dynamic Programming Questions

// 1. Climbing Stairs (Amazon, Salesforce - Very Frequent)
// Count ways to climb n stairs (1 or 2 steps at a time)
// Time: O(n), Space: O(1)
int climbStairs(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

// 2. House Robber (Amazon - Very Frequent)
// Max money robbing houses without adjacent ones
// Time: O(n), Space: O(1)
int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    
    int prev2 = 0, prev1 = 0;
    for (int num : nums) {
        int curr = max(prev1, prev2 + num);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

// 3. Coin Change (Amazon, Salesforce - Very Frequent)
// Minimum coins needed to make amount
// Time: O(amount * n), Space: O(amount)
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] > amount ? -1 : dp[amount];
}

// 4. Longest Increasing Subsequence (Amazon - Very Frequent)
// Length of longest strictly increasing subsequence
// Time: O(n log n), Space: O(n)
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }
    
    return tails.size();
}

// 5. Word Break (Amazon, Salesforce - Very Frequent)
// Check if string can be segmented into dictionary words
// Time: O(n^2 * m) where m is max word length, Space: O(n)
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.length() + 1, false);
    dp[0] = true;
    
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[s.length()];
}

// 6. Unique Paths (Amazon - Frequent)
// Number of paths from top-left to bottom-right in grid
// Time: O(m*n), Space: O(n)
int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j-1];
        }
    }
    
    return dp[n-1];
}

// 7. Jump Game (Amazon - Frequent)
// Check if can reach last index
// Time: O(n), Space: O(1)
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    
    return true;
}

// 8. Decode Ways (Amazon - Frequent)
// Count ways to decode string (A=1, B=2, ..., Z=26)
// Time: O(n), Space: O(1)
int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    
    int prev2 = 1, prev1 = 1;
    
    for (int i = 1; i < s.length(); i++) {
        int curr = 0;
        
        if (s[i] != '0') {
            curr += prev1;
        }
        
        int twoDigit = stoi(s.substr(i-1, 2));
        if (twoDigit >= 10 && twoDigit <= 26) {
            curr += prev2;
        }
        
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

// 9. Longest Common Subsequence (Amazon - Frequent)
// Length of LCS of two strings
// Time: O(m*n), Space: O(n)
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= m; i++) {
        int prev = 0;
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (text1[i-1] == text2[j-1]) {
                dp[j] = prev + 1;
            } else {
                dp[j] = max(dp[j], dp[j-1]);
            }
            prev = temp;
        }
    }
    
    return dp[n];
}

// 10. Edit Distance (Amazon - Frequent)
// Minimum operations to convert word1 to word2
// Time: O(m*n), Space: O(n)
int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<int> dp(n + 1);
    
    for (int j = 0; j <= n; j++) dp[j] = j;
    
    for (int i = 1; i <= m; i++) {
        int prev = dp[0];
        dp[0] = i;
        
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (word1[i-1] == word2[j-1]) {
                dp[j] = prev;
            } else {
                dp[j] = 1 + min({prev, dp[j], dp[j-1]});
            }
            prev = temp;
        }
    }
    
    return dp[n];
}

// 11. Maximum Subarray (Amazon, Salesforce - Very Frequent)
// Find contiguous subarray with largest sum (Kadane's Algorithm)
// Time: O(n), Space: O(1)
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int currSum = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    
    return maxSum;
}

// 12. Best Time to Buy and Sell Stock (Amazon, Salesforce - Very Frequent)
// Maximum profit from one transaction
// Time: O(n), Space: O(1)
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    
    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    
    return maxProfit;
}

// 13. Partition Equal Subset Sum (Amazon - Frequent)
// Check if array can be partitioned into two equal sum subsets
// Time: O(n * sum), Space: O(sum)
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    
    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    
    return dp[target];
}

// 14. Longest Palindromic Subsequence (Amazon - Frequent)
// Length of longest palindromic subsequence
// Time: O(n^2), Space: O(n)
int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<int> dp(n, 1);
    
    for (int len = 2; len <= n; len++) {
        int prev = 0;
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            int temp = dp[j];
            
            if (s[i] == s[j]) {
                dp[j] = (len == 2) ? 2 : prev + 2;
            } else {
                dp[j] = max(dp[j], dp[j-1]);
            }
            
            prev = temp;
        }
    }
    
    return dp[n-1];
}

// 15. Regular Expression Matching (Amazon - Frequent)
// Match string with pattern containing '.' and '*'
// Time: O(m*n), Space: O(n)
bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    
    // Handle patterns like a*, a*b*, etc.
    for (int j = 2; j <= n; j++) {
        if (p[j-1] == '*') {
            dp[j] = dp[j-2];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        vector<bool> newDp(n + 1, false);
        
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') {
                newDp[j] = newDp[j-2];
                if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                    newDp[j] = newDp[j] || dp[j];
                }
            } else if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                newDp[j] = dp[j-1];
            }
        }
        
        dp = newDp;
    }
    
    return dp[n];
}

int main() {
    // Climbing Stairs
    cout << "Climb 5 stairs: " << climbStairs(5) << " ways\n";
    
    // House Robber
    vector<int> houses = {2,7,9,3,1};
    cout << "House Robber: $" << rob(houses) << "\n";
    
    // Coin Change
    vector<int> coins = {1,2,5};
    cout << "Coin Change for 11: " << coinChange(coins, 11) << " coins\n";
    
    // Longest Increasing Subsequence
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    cout << "LIS Length: " << lengthOfLIS(nums1) << "\n";
    
    // Word Break
    vector<string> dict = {"leet","code"};
    cout << "Word Break 'leetcode': " << (wordBreak("leetcode", dict) ? "true" : "false") << "\n";
    
    // Unique Paths
    cout << "Unique Paths (3x7): " << uniquePaths(3, 7) << "\n";
    
    // Jump Game
    vector<int> nums2 = {2,3,1,1,4};
    cout << "Can Jump: " << (canJump(nums2) ? "true" : "false") << "\n";
    
    // Decode Ways
    cout << "Decode Ways '226': " << numDecodings("226") << "\n";
    
    // LCS
    cout << "LCS of 'abcde' and 'ace': " << longestCommonSubsequence("abcde", "ace") << "\n";
    
    // Edit Distance
    cout << "Edit Distance 'horse' to 'ros': " << minDistance("horse", "ros") << "\n";
    
    // Maximum Subarray
    vector<int> nums3 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Max Subarray Sum: " << maxSubArray(nums3) << "\n";
    
    // Best Time to Buy and Sell Stock
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Max Profit: $" << maxProfit(prices) << "\n";
    
    // Partition Equal Subset Sum
    vector<int> nums4 = {1,5,11,5};
    cout << "Can Partition: " << (canPartition(nums4) ? "true" : "false") << "\n";
    
    // Longest Palindromic Subsequence
    cout << "Longest Palindrome Subseq 'bbbab': " << longestPalindromeSubseq("bbbab") << "\n";
    
    // Regular Expression Matching
    cout << "Match 'aa' with 'a*': " << (isMatch("aa", "a*") ? "true" : "false") << "\n";
    
    return 0;
}
