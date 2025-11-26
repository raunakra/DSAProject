#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
