// Question Link : https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_8230764?challengeSlug=striver-sde-challenge&leftPanelTab=3

// TC : O(n) | Approach : 2-Pointer

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    } 

    if(fast == NULL){
        return slow;
    }
    else if(fast->next == NULL){
        return slow->next;
    }
    

}

