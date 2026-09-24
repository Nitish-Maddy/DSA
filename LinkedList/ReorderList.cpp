#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x)
  {
    val = x;
    next = NULL;
  }
};

//Reordered List
void reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    //step 1: find the middle
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //Step 2: Separate the second half
    ListNode* second = slow->next;
    slow->next = NULL;   //Cut the first half

    //Step 3: reverse the second half
    ListNode* prev = NULL;
    ListNode* curr = second;

    while (curr != NULL)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    //prev is the head of reversed second half
    second = prev;

    //Step 4: Merge
    ListNode* first = head;

    while (second != NULL)
    {
        ListNode* firstNext = first->next;
        ListNode* secondNext = second->next;

        first->next = second;
        second->next = firstNext;

        first = firstNext;
        second = secondNext;
    }
}

//Print Linkedlist
void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    //1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List:" << endl;
    printList(head);

    //Reordered the List
    reorderList(head);

    cout << "Reordered List:" << endl;
    printList(head);
    return 0;
}