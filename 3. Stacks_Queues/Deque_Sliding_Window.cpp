#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Sliding Window Maximum
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Stores indices
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove indices out of the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // Remove elements smaller than current element from back
        // to maintain decreasing order
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Add to result if window size is reached
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    
    cout << "Max Sliding Window: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    
    return 0;
}
