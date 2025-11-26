#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

// 1. Fixed Sliding Window (e.g., Maximum Sum Subarray of Size K)
int maxSumSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return -1;
    
    int currentSum = 0;
    for (int i = 0; i < k; i++) {
        currentSum += nums[i];
    }
    
    int maxSum = currentSum;
    for (int i = k; i < n; i++) {
        currentSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

// 2. Variable Sliding Window (e.g., Longest Substring Without Repeating Characters)
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int left = 0;
    int maxLength = 0;
    
    for (int right = 0; right < s.length(); right++) {
        char currentChar = s[right];
        if (charIndexMap.find(currentChar) != charIndexMap.end()) {
            left = max(left, charIndexMap[currentChar] + 1);
        }
        charIndexMap[currentChar] = right;
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

int main() {
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    cout << "Max Sum (k=3): " << maxSumSubarray(nums, 3) << endl;
    
    string s = "abcabcbb";
    cout << "Longest Substring: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
