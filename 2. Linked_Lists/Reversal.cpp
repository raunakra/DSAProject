#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 1. Iterative Reversal
ListNode* reverseListIterative(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// 2. Recursive Reversal
ListNode* reverseListRecursive(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* p = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
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
    
    cout << "Original: ";
    printList(head);
    
    head = reverseListIterative(head);
    cout << "Reversed (Iterative): ";
    printList(head);
    
    head = reverseListRecursive(head);
    cout << "Reversed Back (Recursive): ";
    printList(head);
    
    return 0;
}
