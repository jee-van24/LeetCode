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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        ListNode* curr=head;
        unordered_set<ListNode*>s;
        while(curr!=nullptr){
            if(curr->val<x){
                tail->next=new ListNode(curr->val);
                tail=tail->next;
                s.insert(curr);
            }
            curr=curr->next;
        }
        curr=head;
        while(curr!=nullptr){
            if(!s.count(curr)){
                tail->next=new ListNode(curr->val);
                tail=tail->next;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};