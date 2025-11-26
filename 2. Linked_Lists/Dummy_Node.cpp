#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Remove Nth Node From End of List
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* first = dummy;
    ListNode* second = dummy;
    
    // Move first pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }
    
    // Move both pointers until first reaches the end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    
    // Remove the nth node
    ListNode* temp = second->next;
    second->next = second->next->next;
    delete temp;
    
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Original: ";
    printList(head);
    
    head = removeNthFromEnd(head, 2);
    
    cout << "After removing 2nd from end: ";
    printList(head);
    
    return 0;
}
