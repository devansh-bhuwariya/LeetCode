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
    pair<int,int> getdifference(ListNode* l1,ListNode* l2){
        int count1=0;
        int count2=0;
        while(l1!=nullptr or l2!=nullptr){
            if(l1!=nullptr){
                count1+=1;
                l1=l1->next;
            }
            if(l2!=nullptr){
                count2+=1;
                l2=l2->next;
            }
        }
        return {count1,count2};
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr or headB==nullptr){
            return nullptr;
        }
        ListNode* l1;
        ListNode* l2;
        int count1,count2;
        tie(count1,count2)=getdifference(headA,headB);
        int diff=max(count1-count2,count2-count1);
        if(count1>count2){
            l1=headA;
            l2=headB;
        }else{
            l1=headB;
            l2=headA; 
        }
        while(diff!=0){
            l1=l1->next;
            diff--;
        }
        while(l1!=l2){
            l1=l1->next;
            l2=l2->next;
        }
        return l1;
    }
};