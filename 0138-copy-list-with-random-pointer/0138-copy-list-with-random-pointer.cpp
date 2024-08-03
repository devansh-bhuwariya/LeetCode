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
        unordered_map<Node*,Node*> mem;
        Node* res=new Node(-1);
        Node* result=res;
        Node* temp=head;
        while(temp!=nullptr){
            Node* newNode=new Node(temp->val);
            res->next=newNode;
            mem[temp]=newNode;
            temp=temp->next;
            res=res->next;
            
        }
        temp=head;
        res=result->next;
        while(temp!=nullptr){
            res->random=mem[temp->random];
            res=res->next;
            temp=temp->next;
        }
        return result->next;
        
    }
};