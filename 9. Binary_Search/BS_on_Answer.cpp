#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Example: Split Array Largest Sum (Minimize the largest sum of split)
bool canSplit(vector<int>& nums, int m, int maxSum) {
    int currentSum = 0;
    int splits = 1;
    for (int num : nums) {
        if (currentSum + num > maxSum) {
            currentSum = num;
            splits++;
            if (splits > m) return false;
        } else {
            currentSum += num;
        }
    }
    return true;
}

int splitArray(vector<int>& nums, int m) {
    int left = 0;
    int right = 0;
    for (int num : nums) {
        left = max(left, num);
        right += num;
    }
    
    int result = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canSplit(nums, m, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {7,2,5,10,8};
    cout << "Min Largest Sum (m=2): " << splitArray(nums, 2) << endl;
    return 0;
}
