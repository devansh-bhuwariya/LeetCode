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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1=headA;
        while(l1!=nullptr){
            ListNode* l2=headB;
            while(l2!=nullptr){
                if(l1==l2){
                    return l1;
                }else{
                    l2=l2->next;
                }
            }
            l1=l1->next;
        }
        return nullptr;
    }
};