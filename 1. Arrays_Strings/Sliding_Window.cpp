#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <algorithm>

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

// 3. Minimum Window Substring (Amazon Frequent)
// Given strings s and t, find the minimum window in s which contains all characters of t
// Time: O(|s| + |t|), Space: O(|t|)
string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    
    unordered_map<char, int> tFreq, windowFreq;
    for (char c : t) tFreq[c]++;
    
    int required = tFreq.size();
    int formed = 0;
    int left = 0, right = 0;
    int minLen = INT_MAX;
    int minLeft = 0;
    
    while (right < s.length()) {
        char c = s[right];
        windowFreq[c]++;
        
        if (tFreq.count(c) && windowFreq[c] == tFreq[c]) {
            formed++;
        }
        
        while (left <= right && formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }
            
            char leftChar = s[left];
            windowFreq[leftChar]--;
            if (tFreq.count(leftChar) && windowFreq[leftChar] < tFreq[leftChar]) {
                formed--;
            }
            left++;
        }
        right++;
    }
    
    return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
}

// 4. Longest Substring with At Most K Distinct Characters (Amazon Frequent)
// Time: O(n), Space: O(k)
int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (k == 0) return 0;
    
    unordered_map<char, int> charCount;
    int left = 0, maxLen = 0;
    
    for (int right = 0; right < s.length(); right++) {
        charCount[s[right]]++;
        
        while (charCount.size() > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) {
                charCount.erase(s[left]);
            }
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}

// 5. Max Consecutive Ones III (Amazon Interview Question)
// Given binary array and k flips allowed, find max consecutive 1s
// Time: O(n), Space: O(1)
int longestOnes(vector<int>& nums, int k) {
    int left = 0, maxLen = 0, zeroCount = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeroCount++;
        
        while (zeroCount > k) {
            if (nums[left] == 0) zeroCount--;
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}

// 6. Fruits into Baskets (Amazon - same as longest subarray with at most 2 distinct)
// Time: O(n), Space: O(1)
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> basket;
    int left = 0, maxFruits = 0;
    
    for (int right = 0; right < fruits.size(); right++) {
        basket[fruits[right]]++;
        
        while (basket.size() > 2) {
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0) {
                basket.erase(fruits[left]);
            }
            left++;
        }
        
        maxFruits = max(maxFruits, right - left + 1);
    }
    
    return maxFruits;
}

// 7. Subarray Product Less Than K (Amazon Interview)
// Count subarrays where product of elements < k
// Time: O(n), Space: O(1)
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    
    int product = 1, count = 0, left = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        product *= nums[right];
        
        while (product >= k) {
            product /= nums[left];
            left++;
        }
        
        count += right - left + 1;
    }
    
    return count;
}

int main() {
    // Original examples
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    cout << "Max Sum (k=3): " << maxSumSubarray(nums, 3) << endl;
    
    string s = "abcabcbb";
    cout << "Longest Substring: " << lengthOfLongestSubstring(s) << endl;
    
    // Amazon Interview Questions
    cout << "\n--- Amazon Interview Questions ---\n";
    
    // Minimum Window Substring
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "Min Window Substring: " << minWindow(s1, t1) << endl; // Expected: "BANC"
    
    // Longest Substring with K Distinct
    string s2 = "eceba";
    cout << "Longest K Distinct (k=2): " << lengthOfLongestSubstringKDistinct(s2, 2) << endl; // Expected: 3 ("ece")
    
    // Max Consecutive Ones III
    vector<int> nums2 = {1,1,1,0,0,0,1,1,1,1,0};
    cout << "Max Consecutive Ones (k=2): " << longestOnes(nums2, 2) << endl; // Expected: 6
    
    // Fruits into Baskets
    vector<int> fruits = {1,2,1};
    cout << "Total Fruits: " << totalFruit(fruits) << endl; // Expected: 3
    
    // Subarray Product Less Than K
    vector<int> nums3 = {10,5,2,6};
    cout << "Subarrays Product < 100: " << numSubarrayProductLessThanK(nums3, 100) << endl; // Expected: 8
    
    return 0;
}
