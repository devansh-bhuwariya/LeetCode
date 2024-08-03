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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr or k==1){
            return head;
        }
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* curr=dummy;
        ListNode* prev=dummy;
        ListNode* front=dummy;
        int count=0;
        while(curr->next!=nullptr){
            count+=1;
            curr=curr->next;
        }
        while(count>=k){
            curr=prev->next;
            front=curr->next;
            for(int i=1;i<k;i++){
                curr->next=front->next;
                front->next=prev->next;
                prev->next=front;
                front=curr->next;
            }
            prev=curr;
            count-=k;
        }
        return dummy->next;
    }
};