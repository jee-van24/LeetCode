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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return nullptr;
        ListNode* oddhead=nullptr;
        ListNode* evenhead=nullptr;
        ListNode* oddtail=oddhead;
        ListNode* eventail=evenhead;
        ListNode* curr=head;
        int count=1;
        while(curr!=nullptr){
            if(count%2==1){
                if(!oddhead){
                    oddhead=new ListNode(curr->val);
                    oddtail=oddhead;
                }else{
                    oddtail->next=new ListNode(curr->val);
                    oddtail=oddtail->next;
                }
            }else{
                if(!evenhead){
                    evenhead=new ListNode(curr->val);
                    eventail=evenhead;
                }else{
                    eventail->next=new ListNode(curr->val);
                    eventail=eventail->next;
                }
            }
            curr=curr->next;
            count++;
        }
        oddtail->next=evenhead;
        return oddhead;
    }
};