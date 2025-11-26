#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Same Direction (e.g., Remove Duplicates)
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 0;
    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;
}

// 2. Opposite Direction (e.g., Two Sum II - Input Array Is Sorted)
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

int main() {
    // Example usage
    vector<int> nums = {1, 1, 2};
    cout << "New length: " << removeDuplicates(nums) << endl;
    
    vector<int> sortedNums = {2, 7, 11, 15};
    vector<int> result = twoSum(sortedNums, 9);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}
