#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

// Kth Largest Element in an Array
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}

// Top K Frequent Elements
#include <unordered_map>
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (int n : nums) count[n]++;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
    for (auto& it : count) {
        minHeap.push({it.second, it.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> res;
    while (!minHeap.empty()) {
        res.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return res;
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    cout << "Kth Largest (k=2): " << findKthLargest(nums, 2) << endl;
    
    vector<int> nums2 = {1,1,1,2,2,3};
    vector<int> topK = topKFrequent(nums2, 2);
    cout << "Top 2 Frequent: " << topK[0] << ", " << topK[1] << endl;
    
    return 0;
}
