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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int sum=0;
        while(ptr1!=nullptr || ptr2!=nullptr){
            if (ptr1 != nullptr) {
                sum += ptr1->val;
                ptr1 = ptr1->next;
            }
            if (ptr2 != nullptr) {
                sum += ptr2->val;
                ptr2 = ptr2->next;
            }
            
            temp->next=new ListNode(sum%10);
            sum=sum/10;
            temp=temp->next;
        }
        if(sum>0){
            temp->next=new ListNode(sum%10);
        }
        return dummy->next;
    }
};