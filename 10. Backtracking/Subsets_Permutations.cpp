#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Subsets and Permutations - Common Backtracking Patterns
//
// This file demonstrates two fundamental backtracking patterns:
//
// 1. SUBSETS (Power Set)
//    Problem: Given an integer array nums of unique elements, return all possible subsets (the power set).
//    Example:
//      Input: nums = [1,2,3]
//      Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//    Approach: Use backtracking to build subsets incrementally. At each step, include or exclude the current element.
//    Time Complexity: O(N * 2^N) - there are 2^N subsets and each takes O(N) to copy
//    Space Complexity: O(N) for recursion stack depth
//
// 2. PERMUTATIONS
//    Problem: Given an array nums of distinct integers, return all possible permutations.
//    Example:
//      Input: nums = [1,2,3]
//      Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//    Approach: Use backtracking with swapping. Fix one element at a time and recursively permute the rest.
//    Time Complexity: O(N * N!) - N! permutations and each takes O(N) to copy
//    Space Complexity: O(N) for recursion stack depth

// 1. Subsets
void subsetsUtil(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    for (int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]);
        subsetsUtil(nums, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    subsetsUtil(nums, 0, current, result);
    return result;
}

// 2. Permutations
void permuteUtil(vector<int>& nums, vector<vector<int>>& result, int start) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permuteUtil(nums, result, start + 1);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permuteUtil(nums, result, 0);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subs = subsets(nums);
    cout << "Total Subsets: " << subs.size() << endl;
    
    vector<vector<int>> perms = permute(nums);
    cout << "Total Permutations: " << perms.size() << endl;
    
    return 0;
}
