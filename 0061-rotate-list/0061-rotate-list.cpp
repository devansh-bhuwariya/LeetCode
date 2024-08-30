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
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head==nullptr or head->next==nullptr or k==0) return head;
//         ListNode* fast=head;
//         int count=0;
//         while(fast!=nullptr){
//             count++;
//             fast=fast->next;
//         }
//         k=k%count;
//         fast=head;
//         for(int i=1;i<=k;i++){    
//             fast=fast->next;
//         }
//         ListNode* slow=head;
//         while(fast->next!=nullptr){
//             slow=slow->next;
//             fast=fast->next;
//         }
//         ListNode* res=slow->next;
//         slow->next=nullptr;
//         fast->next=head;
//         return res;
//     }
// };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr or head->next==nullptr or k==0) return head;
        ListNode* temp=head;
        int len=1;
        while(temp->next!=nullptr){
            len++;
            temp=temp->next;
        }
        temp->next=head;
        temp=temp->next;
        k=k%len;  //3%5=2
        k=len-k;  //5-2=3
        for(int i=1;i<k;i++){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};