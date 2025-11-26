#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 1. Detect Cycle
bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return false;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// 2. Detect Cycle Start Node
ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    bool hasCycle = false;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }
    
    if (!hasCycle) return NULL;
    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node0 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);
    
    head->next = node2;
    node2->next = node0;
    node0->next = node4;
    node4->next = node2; // Cycle
    
    cout << "Has Cycle: " << hasCycle(head) << endl;
    
    ListNode* cycleStart = detectCycle(head);
    if (cycleStart) {
        cout << "Cycle starts at val: " << cycleStart->val << endl;
    }
    
    return 0;
}
