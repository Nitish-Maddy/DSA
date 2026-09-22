#include <iostream>
using namespace std;

//Definition of Linked List Node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
 public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;     //here slow traverse half of node while fast complete the node so slow at middle i.e. we return slow..
    }    
};

int main() {
    //Creating LinkedList:
    // 1->2->3->4->5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    //create Solution
    Solution obj;

    // find middle
    ListNode* middle = obj.middleNode(head);
    cout << "Middle node = " << middle->val << endl;
    return 0;
}