// Question Link : https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_8230729?challengeSlug=striver-sde-challenge&leftPanelTab=3

// Approach : Without Creating Another LL

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }


    Node<int> *finalHead = NULL;
    Node<int> *finalTail = NULL;

    while(first != NULL && second != NULL){
        if(first->data < second->data){
            if(finalHead == NULL){
                finalHead = first;
                finalTail = first;
                first = first->next;
                continue;
            }
            finalTail->next = first;
            finalTail = finalTail->next;
            first = first->next;
        }
        else{
            if(finalHead == NULL){
                finalHead = second;
                finalTail = second;
                second = second->next;
                continue;
            }
            finalTail->next = second;
            finalTail = finalTail->next;
            second = second->next;
        }
    }

    if(first != NULL){
        finalTail->next = first;
    }

    if(second != NULL){
        finalTail->next = second;
    }

    return finalHead;
}
