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

//Reverse the LinkedList
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    
    while(curr != NULL) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

//Remove nodes having a greater value to their right
ListNode* removeNodes(ListNode* head) {
    //Step1: Reverse the list
    head = reverseList(head);

    //step2: remove smaller nodes
    int maxVal = head->val;
    ListNode* curr = head;

    while(curr != NULL && curr->next != NULL) {
        if(curr->next->val < maxVal) {
            curr->next = curr->next->next;
        }
        else{
            curr = curr->next;
            maxVal = curr->val;
        }
    }

    //Step3: Restore original order
    head = reverseList(head);
    
    return head;
}

//Print the Linked List
void printList(ListNode* head) {
    while( head != NULL) {
        cout << head->val;

        if(head->next != NULL) {
            cout << " -> ";
        }

        head = head->next; 
    }
    cout << endl; 
}

int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    cout << "Original list: ";
    printList(head);

    head = removeNodes(head);

    cout << "Modified list: ";
    printList(head);

    return 0;
}