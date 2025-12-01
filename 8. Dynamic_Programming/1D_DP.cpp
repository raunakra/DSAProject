#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Climbing Stairs
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


// 2. House Robber
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    int prev2 = 0;
    int prev1 = nums[0];
    
    for (int i = 1; i < n; i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    cout << "Climb Stairs (5): " << climbStairs(5) << endl;
    
    vector<int> houses = {2, 7, 9, 3, 1};
    cout << "Max Rob Amount: " << rob(houses) << endl;
    return 0;
}
