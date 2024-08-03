/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr or head->next==nullptr){
            return head;
        }
        ListNode* temp=new ListNode();
        temp->next=head;
        ListNode* dummy=temp;
        int count=0;
        while(temp->next!=nullptr){
            count+=1;
            temp=temp->next;
        }
        temp->next=head;
        if(k>=count){
            k=k%count;
        }
        k=count-k;
        while(k!=0){
            dummy=dummy->next;
            k-=1;
        }
        head=dummy->next;
        dummy->next=nullptr;
        return head;
    }
};