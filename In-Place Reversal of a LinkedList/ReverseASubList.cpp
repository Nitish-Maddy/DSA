#include <iostream>
using namespace std;

//Structure of a Singly linked List node
struct ListNode {
    int val;
    ListNode* next;
    
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
     // if the list is empty, return null
     if(head == NULL) {
        return NULL;
     }

     // If left and right are equal, no reversal is needed
     if(left == right) {
        return NULL;
     }
     
     ListNode* t = head;
     ListNode* before = NULL;
     int pos = 1;

     //Move t to the node at position left
     //before stores the node just before t
     while(pos < left) {
        before = t;
        t = t->next;
        pos++;
     }

     //Start reversing the sublist from position left
     ListNode* curr = t;
     ListNode* prev = NULL;

     //Number of nodes that must be reversed
     int times = right - left + 1;

     //Reverse exactly the nodes from left to right
     while(times--) {

        //Save the next node before changing the link
        ListNode* next = curr->next;

        //reverse the current node's pointer
        curr->next = prev;
        //Move prev forward to the current node
        prev = curr;
        //move curr forward to the saved next node
        curr = next;
     }

     //t was the first node of the sublist.
     //After reversal, t becomes its last node
     //Connect it to the remaining part of the list.
     t->next = curr;

     //if a node exists before the reversed sublists,
     //connect it to the new head of the reversal sublist
     if (before != NULL) {
        before->next = prev;
        return head;
     }

     //if left == 1, prev becomes the new head of the list
     return prev;

    }
};

//Function to print Linked List 
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;

        if (head->next != NULL) {
            cout << " -> ";
        }

        head = head->next;
    }
    cout << endl;
}

int main() {
    //Create the linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    //reverse the node from position 2 to position 4
    int left = 2;
    int right = 4;

    Solution obj;

    //Update head because the first node might change
    head = obj.reverseBetween(head, left, right);

    //print the final linked list
    cout << "Reversed list: ";
    printList(head);

    return 0;
}