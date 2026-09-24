#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode*next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};

//Reverse a linked list
ListNode* reverseList(ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr != NULL)
    {
       ListNode* nextNode = curr->next;  //save next
        curr->next = prev;                //change arrow
        prev = curr;                      //move prev
        curr = nextNode;                  //move curr
    }
    return prev;
}

bool isPalindrome(ListNode* head)
{
    //1.Empty list or one node
    if (head == NULL || head->next == NULL) {
        return true;
    }

    //2.find the middle
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //3.Reverse the second half
    ListNode* secondHalf = reverseList(slow);

    //4.Compare first half and reverse second half
    ListNode* firstHalf = head;

    while (secondHalf != NULL)
    {
        if (firstHalf->val != secondHalf->val){
            return false;
        }

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

int main() {
    // 1->2->2->1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if (isPalindrome(head))
    {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}