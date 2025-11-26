#include <iostream>
#include <vector>

using namespace std;

// Prefix Sum Array Construction
vector<int> buildPrefixSum(const vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    return prefix;
}

// Range Sum Query
int rangeSum(const vector<int>& prefix, int left, int right) {
    // Returns sum of nums[left...right] (0-indexed)
    return prefix[right + 1] - prefix[left];
}

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    vector<int> prefix = buildPrefixSum(nums);
    
    // Sum of range [0, 2] -> -2 + 0 + 3 = 1
    cout << "Range Sum [0, 2]: " << rangeSum(prefix, 0, 2) << endl;
    
    // Sum of range [2, 5] -> 3 + -5 + 2 + -1 = -1
    cout << "Range Sum [2, 5]: " << rangeSum(prefix, 2, 5) << endl;
    
    return 0;
}
