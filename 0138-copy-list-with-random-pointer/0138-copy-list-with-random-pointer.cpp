/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==NULL){
            return head;
        }
        Node* temp=head;
        Node* dummy=new Node(-1);
        while(temp!=NULL){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random==NULL){
                temp->next->random=NULL;
            }else{
                temp->next->random=temp->random->next;
            }  
            temp=temp->next->next;
        }
        temp=head;
        head=temp->next;
        while(temp->next->next!=NULL){
            dummy=temp->next;
            temp->next=dummy->next;
            temp=temp->next;
            dummy->next=temp->next;
        }
        temp->next=NULL;
        return head;
        
    }
};