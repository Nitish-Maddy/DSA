#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current && current->next) {
            if (current->val == current->next->val) {
                current->next = current->next->next;;
            }
            else {
                current = current->next;
            }
        }
        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        
        if (head->next) {
            cout<< " -> ";
        }

        head = head->next;
    }
    cout << " -> NuLL " << endl;
}

int main() {
    // Create a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3 ->NuLL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Before removing duplicates:" << endl;
    printList(head);

    Solution obj;
    head = obj.deleteDuplicates(head);

    cout << "After removing duplicates:" << endl;
    printList(head);

    return 0;
}