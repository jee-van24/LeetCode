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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=fast;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(!fast){
            return head->next;
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* todel=slow->next;
        slow->next=slow->next->next;
        delete todel;
        return head;
    }
};