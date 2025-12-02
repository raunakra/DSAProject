#include <bits/stdc++.h>
using namespace std;

// Amazon & Salesforce Frequently Asked Array/String Questions
// Time and Space complexities noted for each problem

// 1. Two Sum (Amazon, Salesforce - Very Frequent)
// Given array and target, return indices of two numbers that add up to target
// Time: O(n), Space: O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.count(complement)) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

// 2. Three Sum (Amazon - Very Frequent)
// Find all unique triplets that sum to zero
// Time: O(n²), Space: O(1) excluding output
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left+1]) left++;
                while (left < right && nums[right] == nums[right-1]) right--;
                left++; right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}

// 3. Container With Most Water (Amazon - Frequent)
// Find two lines that together with x-axis form container with most water
// Time: O(n), Space: O(1)
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;
    
    while (left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);
        maxWater = max(maxWater, width * h);
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxWater;
}

// 4. Trapping Rain Water (Amazon - Very Frequent)
// Calculate how much water can be trapped after raining
// Time: O(n), Space: O(1)
int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }
    return water;
}

// 5. Valid Parentheses (Amazon, Salesforce - Very Frequent)
// Determine if string of brackets is valid
// Time: O(n), Space: O(n)
bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    
    for (char c : s) {
        if (pairs.count(c)) {
            if (st.empty() || st.top() != pairs[c]) return false;
            st.pop();
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

// 6. Longest Palindromic Substring (Amazon - Frequent)
// Find the longest palindromic substring
// Time: O(n²), Space: O(1)
string longestPalindrome(string s) {
    if (s.empty()) return "";
    int start = 0, maxLen = 1;
    
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        int len = right - left - 1;
        if (len > maxLen) {
            maxLen = len;
            start = left + 1;
        }
    };
    
    for (int i = 0; i < s.length(); i++) {
        expandAroundCenter(i, i);     // odd length
        expandAroundCenter(i, i + 1); // even length
    }
    
    return s.substr(start, maxLen);
}

// 7. Group Anagrams (Amazon - Frequent)
// Group strings that are anagrams of each other
// Time: O(n * k log k) where k is max string length, Space: O(n * k)
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    
    for (string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        map[key].push_back(s);
    }
    
    vector<vector<string>> result;
    for (auto& [key, group] : map) {
        result.push_back(group);
    }
    return result;
}

// 8. Meeting Rooms II (Amazon - Very Frequent, Salesforce - Frequent)
// Find minimum number of conference rooms required
// Time: O(n log n), Space: O(n)
int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    vector<int> start, end;
    for (auto& interval : intervals) {
        start.push_back(interval[0]);
        end.push_back(interval[1]);
    }
    
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    int rooms = 0, endIdx = 0;
    for (int i = 0; i < start.size(); i++) {
        if (start[i] < end[endIdx]) {
            rooms++;
        } else {
            endIdx++;
        }
    }
    return rooms;
}

// 9. Merge Intervals (Amazon, Salesforce - Very Frequent)
// Merge overlapping intervals
// Time: O(n log n), Space: O(n)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged = {intervals[0]};
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

// 10. Product of Array Except Self (Amazon - Very Frequent)
// Return array where output[i] = product of all elements except nums[i]
// Time: O(n), Space: O(1) excluding output array
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }
    
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }
    
    return result;
}

// 11. Integer to Roman (Amazon, Salesforce - Frequent)
// Convert integer to Roman numeral
// Time: O(1), Space: O(1)
string intToRoman(int num) {
    vector<pair<int, string>> values = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    
    string result;
    for (auto& [val, symbol] : values) {
        while (num >= val) {
            result += symbol;
            num -= val;
        }
    }
    return result;
}

// 12. Roman to Integer (Amazon, Salesforce - Frequent)
// Convert Roman numeral to integer
// Time: O(n), Space: O(1)
int romanToInt(string s) {
    unordered_map<char, int> map = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i + 1 < s.length() && map[s[i]] < map[s[i+1]]) {
            result -= map[s[i]];
        } else {
            result += map[s[i]];
        }
    }
    return result;
}

int main() {
    // Two Sum
    vector<int> nums1 = {2, 7, 11, 15};
    auto res1 = twoSum(nums1, 9);
    cout << "Two Sum: [" << res1[0] << ", " << res1[1] << "]\n";
    
    // Three Sum
    vector<int> nums2 = {-1, 0, 1, 2, -1, -4};
    auto res2 = threeSum(nums2);
    cout << "Three Sum: " << res2.size() << " triplets\n";
    
    // Container With Most Water
    vector<int> height1 = {1,8,6,2,5,4,8,3,7};
    cout << "Max Area: " << maxArea(height1) << "\n";
    
    // Trapping Rain Water
    vector<int> height2 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped Water: " << trap(height2) << "\n";
    
    // Valid Parentheses
    cout << "Valid Parentheses: " << (isValid("()[]{}") ? "true" : "false") << "\n";
    
    // Longest Palindrome
    cout << "Longest Palindrome: " << longestPalindrome("babad") << "\n";
    
    // Group Anagrams
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    cout << "Anagram Groups: " << groupAnagrams(strs).size() << "\n";
    
    // Meeting Rooms
    vector<vector<int>> meetings = {{0,30},{5,10},{15,20}};
    cout << "Min Meeting Rooms: " << minMeetingRooms(meetings) << "\n";
    
    // Merge Intervals
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    cout << "Merged Intervals: " << merge(intervals).size() << "\n";
    
    // Product Except Self
    vector<int> nums3 = {1,2,3,4};
    auto prod = productExceptSelf(nums3);
    cout << "Product Except Self: [";
    for (int p : prod) cout << p << " ";
    cout << "]\n";
    
    // Roman Conversions
    cout << "12 to Roman: " << intToRoman(12) << "\n";
    cout << "XII to Int: " << romanToInt("XII") << "\n";
    
    return 0;
}
