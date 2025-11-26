#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Next Greater Element
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s; // Stores indices
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[s.top()] < nums[i]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    return result;
}

// Next Smaller Element
vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s; // Stores indices
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[s.top()] > nums[i]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    return result;
}

int main() {
    vector<int> nums = {2, 1, 2, 4, 3};
    vector<int> nge = nextGreaterElement(nums);
    
    cout << "Next Greater Elements: ";
    for (int x : nge) cout << x << " ";
    cout << endl;
    
    return 0;
}
