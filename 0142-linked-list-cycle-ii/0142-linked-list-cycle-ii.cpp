/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr or head->next==nullptr) return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr and fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        fast=head;
        while(slow!=nullptr){
            if(fast==slow) return fast;
            fast=fast->next;
            slow=slow->next;
        }
        return nullptr;
    }
};