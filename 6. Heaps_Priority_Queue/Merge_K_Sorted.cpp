#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
    
    for (ListNode* list : lists) {
        if (list) minHeap.push(list);
    }
    
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    
    while (!minHeap.empty()) {
        ListNode* top = minHeap.top();
        minHeap.pop();
        
        tail->next = top;
        tail = tail->next;
        
        if (top->next) {
            minHeap.push(top->next);
        }
    }
    return dummy->next;
}

int main() {
    // Example setup omitted for brevity
    cout << "Merge K Lists function ready." << endl;
    return 0;
}
