// Question Link : 
// Code Studio : https://www.codingninjas.com/codestudio/problems/palindrome-linked-list_8230717?challengeSlug=striver-sde-challenge&leftPanelTab=1
// LeetCode : https://leetcode.com/problems/palindrome-linked-list/submissions/970229282/

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* reverse(LinkedListNode<int> *head){
    if(head == NULL){
        return NULL;
    }
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *next = head->next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL){
        return true;
    }

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    LinkedListNode<int> *head1 = head;
    LinkedListNode<int> *tail1 = slow;
    LinkedListNode<int> *head2 = slow->next;
    LinkedListNode<int> *tail2 = slow->next;
    slow->next = NULL;

    while(tail2->next != NULL){
        tail2 = tail2->next;
    }

    head2 = reverse(head2);

    while(head1 != NULL && head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;

}
