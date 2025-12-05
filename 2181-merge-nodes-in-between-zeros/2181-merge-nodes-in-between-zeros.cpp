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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* curr=head->next;
        int s=0;
        while(curr){
            s+=curr->val;
            if(curr->val==0){
                //make a new node here , and join it to the new ll
                temp->next=new ListNode(s);
                temp=temp->next;
                cout<<s<<" ";
                s=0;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};