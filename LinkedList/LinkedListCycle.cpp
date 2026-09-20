#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

#define ed endl
#define Node ListNode
#define null NULL

class Solution {
    public:

    bool hasCycle(ListNode *head) {
        if(head == null)
        return false;

        if(head->next == null)
        return false;

        Node* slow = head;
        Node* fast = head;

        while(fast != null and fast->next != null)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            return true;
        }
        
        return false;
    }
};

int main() {

    //Creating Nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    //Creating a cycle:
    // 1->2->3->4
    //    ^      |
    //    |______|

    head->next->next->next->next = head->next;

    Solution obj;
    if(obj.hasCycle(head))
     cout << "Cycle exists" << ed;
     else
        cout << "No Cycle" << ed;

        return 0;
}