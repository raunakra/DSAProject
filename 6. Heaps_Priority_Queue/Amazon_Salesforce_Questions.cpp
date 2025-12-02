#include <bits/stdc++.h>
using namespace std;

// Amazon & Salesforce Frequently Asked Heaps/Priority Queue Questions

// 1. Top K Frequent Elements (Amazon, Salesforce - Very Frequent)
// Return k most frequent elements
// Time: O(n log k), Space: O(n)
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    // Min heap based on frequency
    auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    
    for (auto& [num, count] : freq) {
        pq.push({num, count});
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }
    
    return result;
}

// 2. Find Median from Data Stream (Amazon, Salesforce - Very Frequent)
// Maintain median with two heaps
// Time: O(log n) for addNum, O(1) for findMedian, Space: O(n)
class MedianFinder {
    priority_queue<int> maxHeap; // Lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Upper half
    
public:
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Balance heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

// 3. Merge K Sorted Lists (Amazon - Very Frequent)
// Merge k sorted linked lists
// Time: O(N log k) where N is total nodes, Space: O(k)
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) {
        return a->val > b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    
    for (ListNode* list : lists) {
        if (list) pq.push(list);
    }
    
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        
        tail->next = node;
        tail = tail->next;
        
        if (node->next) {
            pq.push(node->next);
        }
    }
    
    return dummy.next;
}

// 4. Kth Largest Element in Array (Amazon, Salesforce - Very Frequent)
// Find kth largest element
// Time: O(n log k), Space: O(k)
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

// 5. Task Scheduler (Amazon - Frequent)
// Minimum intervals to execute all tasks with cooldown
// Time: O(n), Space: O(1) - only 26 letters
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char task : tasks) {
        freq[task - 'A']++;
    }
    
    sort(freq.rbegin(), freq.rend());
    int maxFreq = freq[0];
    int idleTime = (maxFreq - 1) * n;
    
    for (int i = 1; i < 26 && freq[i] > 0; i++) {
        idleTime -= min(freq[i], maxFreq - 1);
    }
    
    idleTime = max(0, idleTime);
    return tasks.size() + idleTime;
}

// 6. Reorganize String (Amazon - Frequent)
// Rearrange so no two adjacent characters are same
// Time: O(n log 26) = O(n), Space: O(26) = O(1)
string reorganizeString(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    
    priority_queue<pair<int, char>> pq;
    for (auto& [ch, count] : freq) {
        pq.push({count, ch});
    }
    
    string result;
    pair<int, char> prev = {-1, '#'};
    
    while (!pq.empty()) {
        auto [count, ch] = pq.top();
        pq.pop();
        
        result += ch;
        
        if (prev.first > 0) {
            pq.push(prev);
        }
        
        prev = {count - 1, ch};
    }
    
    return result.length() == s.length() ? result : "";
}

// 7. Meeting Rooms II (Amazon - Very Frequent)
// Minimum conference rooms needed
// Time: O(n log n), Space: O(n)
int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> pq; // Min heap of end times
    
    pq.push(intervals[0][1]);
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= pq.top()) {
            pq.pop();
        }
        pq.push(intervals[i][1]);
    }
    
    return pq.size();
}

// 8. Kth Smallest Element in Sorted Matrix (Amazon - Frequent)
// Find kth smallest in n×n matrix
// Time: O(k log n), Space: O(n)
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    
    auto cmp = [&](pair<int,int>& a, pair<int,int>& b) {
        return matrix[a.first][a.second] > matrix[b.first][b.second];
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    
    for (int i = 0; i < min(n, k); i++) {
        pq.push({i, 0});
    }
    
    int result = 0;
    for (int i = 0; i < k; i++) {
        auto [row, col] = pq.top();
        pq.pop();
        result = matrix[row][col];
        
        if (col + 1 < n) {
            pq.push({row, col + 1});
        }
    }
    
    return result;
}

// 9. Sliding Window Maximum (Amazon - Frequent)
// Maximum in each sliding window of size k
// Time: O(n), Space: O(k) using deque
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Stores indices
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove elements outside window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove smaller elements from back
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}

// 10. Sort Characters By Frequency (Amazon - Frequent)
// Sort characters by frequency (descending)
// Time: O(n log n), Space: O(n)
string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    
    priority_queue<pair<int, char>> pq;
    for (auto& [ch, count] : freq) {
        pq.push({count, ch});
    }
    
    string result;
    while (!pq.empty()) {
        auto [count, ch] = pq.top();
        pq.pop();
        result.append(count, ch);
    }
    
    return result;
}

// 11. Ugly Number II (Amazon - Frequent)
// Find nth ugly number (factors are only 2, 3, 5)
// Time: O(n), Space: O(n)
int nthUglyNumber(int n) {
    vector<int> ugly(n);
    ugly[0] = 1;
    
    int i2 = 0, i3 = 0, i5 = 0;
    int next2 = 2, next3 = 3, next5 = 5;
    
    for (int i = 1; i < n; i++) {
        int nextUgly = min({next2, next3, next5});
        ugly[i] = nextUgly;
        
        if (nextUgly == next2) {
            i2++;
            next2 = ugly[i2] * 2;
        }
        if (nextUgly == next3) {
            i3++;
            next3 = ugly[i3] * 3;
        }
        if (nextUgly == next5) {
            i5++;
            next5 = ugly[i5] * 5;
        }
    }
    
    return ugly[n - 1];
}

// 12. K Closest Points to Origin (Amazon, Salesforce - Very Frequent)
// Find k closest points to origin
// Time: O(n log k), Space: O(k)
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto dist = [](const vector<int>& p) {
        return p[0] * p[0] + p[1] * p[1];
    };
    
    auto cmp = [&](const vector<int>& a, const vector<int>& b) {
        return dist(a) < dist(b);
    };
    
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    
    for (const auto& point : points) {
        pq.push(point);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    vector<vector<int>> result;
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }
    
    return result;
}

int main() {
    // Top K Frequent Elements
    vector<int> nums1 = {1,1,1,2,2,3};
    auto topK = topKFrequent(nums1, 2);
    cout << "Top 2 Frequent: ";
    for (int x : topK) cout << x << " ";
    cout << "\n";
    
    // Median Finder
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << "\n";
    mf.addNum(3);
    cout << "Median after adding 3: " << mf.findMedian() << "\n";
    
    // Kth Largest Element
    vector<int> nums2 = {3,2,1,5,6,4};
    cout << "2nd Largest: " << findKthLargest(nums2, 2) << "\n";
    
    // Task Scheduler
    vector<char> tasks = {'A','A','A','B','B','B'};
    cout << "Least Interval (n=2): " << leastInterval(tasks, 2) << "\n";
    
    // Reorganize String
    cout << "Reorganize 'aab': " << reorganizeString("aab") << "\n";
    
    // Meeting Rooms II
    vector<vector<int>> meetings = {{0,30},{5,10},{15,20}};
    cout << "Min Meeting Rooms: " << minMeetingRooms(meetings) << "\n";
    
    // Kth Smallest in Sorted Matrix
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    cout << "8th Smallest in Matrix: " << kthSmallest(matrix, 8) << "\n";
    
    // Sliding Window Maximum
    vector<int> nums3 = {1,3,-1,-3,5,3,6,7};
    auto maxWindow = maxSlidingWindow(nums3, 3);
    cout << "Sliding Window Max (k=3): ";
    for (int x : maxWindow) cout << x << " ";
    cout << "\n";
    
    // Frequency Sort
    cout << "Frequency Sort 'tree': " << frequencySort("tree") << "\n";
    
    // Ugly Number II
    cout << "10th Ugly Number: " << nthUglyNumber(10) << "\n";
    
    // K Closest Points
    vector<vector<int>> points = {{1,3},{-2,2},{5,8},{0,1}};
    auto closest = kClosest(points, 2);
    cout << "2 Closest Points: ";
    for (const auto& p : closest) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << "\n";
    
    return 0;
}
