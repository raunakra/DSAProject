#include <bits/stdc++.h>
using namespace std;

// Amazon & Salesforce Frequently Asked Linked List Questions

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 1. Reverse Linked List (Amazon, Salesforce - Very Frequent)
// Time: O(n), Space: O(1)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (curr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// 2. Merge Two Sorted Lists (Amazon, Salesforce - Very Frequent)
// Time: O(n + m), Space: O(1)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// 3. Add Two Numbers (Amazon - Very Frequent)
// Add two numbers represented by linked lists (digits in reverse order)
// Time: O(max(m, n)), Space: O(max(m, n))
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }
    
    return dummy.next;
}

// 4. Remove Nth Node From End (Amazon - Frequent)
// Time: O(n), Space: O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;
    
    // Move fast n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move both until fast reaches end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // Remove nth node
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    
    return dummy.next;
}

// 5. Linked List Cycle (Amazon, Salesforce - Very Frequent)
// Detect if linked list has a cycle
// Time: O(n), Space: O(1)
bool hasCycle(ListNode *head) {
    if (!head) return false;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    
    return false;
}

// 6. Linked List Cycle II (Amazon - Frequent)
// Find the node where cycle begins
// Time: O(n), Space: O(1)
ListNode *detectCycle(ListNode *head) {
    if (!head) return nullptr;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    // Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    
    if (!fast || !fast->next) return nullptr;
    
    // Find cycle start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

// 7. Intersection of Two Linked Lists (Amazon - Frequent)
// Find node where two lists intersect
// Time: O(m + n), Space: O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    
    ListNode* pA = headA;
    ListNode* pB = headB;
    
    while (pA != pB) {
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
    }
    
    return pA;
}

// 8. Palindrome Linked List (Amazon - Frequent)
// Check if linked list is palindrome
// Time: O(n), Space: O(1)
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    
    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    ListNode* secondHalf = reverseList(slow->next);
    
    // Compare
    ListNode* p1 = head;
    ListNode* p2 = secondHalf;
    bool result = true;
    while (p2) {
        if (p1->val != p2->val) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    // Restore list (optional)
    slow->next = reverseList(secondHalf);
    
    return result;
}

// 9. Copy List with Random Pointer (Amazon - Very Frequent)
// Deep copy a linked list with next and random pointer
// Time: O(n), Space: O(1) optimized approach
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    
    // Step 1: Create copy nodes interleaved with original
    Node* curr = head;
    while (curr) {
        Node* copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }
    
    // Step 2: Assign random pointers
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    
    // Step 3: Separate lists
    Node* copyHead = head->next;
    curr = head;
    while (curr) {
        Node* copy = curr->next;
        curr->next = copy->next;
        if (copy->next) {
            copy->next = copy->next->next;
        }
        curr = curr->next;
    }
    
    return copyHead;
}

// 10. Reorder List (Amazon - Frequent)
// Reorder L0→L1→…→Ln-1→Ln to L0→Ln→L1→Ln-1→L2→Ln-2→…
// Time: O(n), Space: O(1)
void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    
    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    ListNode* second = reverseList(slow->next);
    slow->next = nullptr;
    
    // Merge two halves
    ListNode* first = head;
    while (second) {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;
        
        first->next = second;
        second->next = tmp1;
        
        first = tmp1;
        second = tmp2;
    }
}

// Helper: Create linked list from vector
ListNode* createList(vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Helper: Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Reverse List
    vector<int> v1 = {1, 2, 3, 4, 5};
    ListNode* list1 = createList(v1);
    cout << "Original: ";
    printList(list1);
    list1 = reverseList(list1);
    cout << "Reversed: ";
    printList(list1);
    
    // Merge Two Sorted Lists
    vector<int> v2 = {1, 2, 4};
    vector<int> v3 = {1, 3, 4};
    ListNode* l1 = createList(v2);
    ListNode* l2 = createList(v3);
    ListNode* merged = mergeTwoLists(l1, l2);
    cout << "\nMerged: ";
    printList(merged);
    
    // Add Two Numbers
    vector<int> v4 = {2, 4, 3}; // 342
    vector<int> v5 = {5, 6, 4}; // 465
    ListNode* num1 = createList(v4);
    ListNode* num2 = createList(v5);
    ListNode* sum = addTwoNumbers(num1, num2);
    cout << "\nSum (342 + 465 = 807): ";
    printList(sum);
    
    // Palindrome Check
    vector<int> v6 = {1, 2, 2, 1};
    ListNode* pal = createList(v6);
    cout << "\nIs Palindrome [1,2,2,1]: " << (isPalindrome(pal) ? "true" : "false") << "\n";
    
    return 0;
}
