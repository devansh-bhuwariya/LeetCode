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
        int l1=0;
        int l2=0;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=nullptr or tempB!=nullptr){
            if(tempA!=nullptr){
                l1++;
                tempA=tempA->next;
            }
            if(tempB!=nullptr){
                l2++;
                tempB=tempB->next;
            }
        }
        tempA=headA;
        tempB=headB;
        if(l1>l2){
            for(int i=1;i<=l1-l2;i++){
                tempA=tempA->next;
            }
        }else{
            for(int i=1;i<=l2-l1;i++){
                tempB=tempB->next;
            }
        }
        while(tempA!=nullptr or tempB!=nullptr){
            if(tempA==tempB) return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return nullptr;
    }
};