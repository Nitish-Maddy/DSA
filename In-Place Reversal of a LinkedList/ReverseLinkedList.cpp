#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
         ListNode* reverseList(ListNode* head) {
            ListNode* curr = head;
            ListNode* prev = NULL;

            while(curr != NULL)
            {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            return prev;
         }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    head = sol.reverseList(head);

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
    return 0;
}