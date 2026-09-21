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

class Solution {
    public:
      ListNode* detectCycle(ListNode* head) {

        //Step1: find whether a cycle exist
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL)
      {
        slow = slow->next;
        fast = fast->next->next;

        //Cycle found
        if(slow == fast) {

            //Step2: find starting node of cycle
            slow = head;

            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
      }
      // No Cycle
      return NULL;
    }
};

int main() {

    //Create Nodes
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    //Create linked list
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    //create cycle: 5 -> 3
    node5->next = node3;

    //Create Solution object
    Solution obj;

    //Find cycle beginning
    ListNode* result = obj.detectCycle(node1);

    if(result != NULL) {
        cout << "Cycle begins at node: " << result->val << endl;
    }
    else {
        cout << "No cycle found" << endl;
    }
    return 0;
}