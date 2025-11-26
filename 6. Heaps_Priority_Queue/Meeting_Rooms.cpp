#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Meeting Rooms II (Min conference rooms required)
int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    sort(intervals.begin(), intervals.end());
    
    priority_queue<int, vector<int>, greater<int>> minHeap; // Stores end times
    minHeap.push(intervals[0][1]);
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= minHeap.top()) {
            minHeap.pop();
        }
        minHeap.push(intervals[i][1]);
    }
    
    return minHeap.size();
}

int main() {
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Min Meeting Rooms: " << minMeetingRooms(intervals) << endl;
    return 0;
}
