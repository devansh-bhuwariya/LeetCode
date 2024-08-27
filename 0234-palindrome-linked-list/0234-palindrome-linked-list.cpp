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
    ListNode* rev(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        bool ans=true;
        if(head->next==nullptr) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr and fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        slow->next=rev(slow->next);
        slow=slow->next;
        ListNode* d=head;
        while(slow!=nullptr){
            if(d->val==slow->val){
                d=d->next;
                slow=slow->next;
            }else{
                ans=false;
                break;
            }
        }
        slow=head;
        fast=head;
        while(fast->next!=nullptr and fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        slow->next=rev(slow->next);
        
        return ans;
    }
};