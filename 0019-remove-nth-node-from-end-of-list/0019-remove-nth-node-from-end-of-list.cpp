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
        ListNode* to_delete=head;
        ListNode* curr=head;
        if(!head)return nullptr;
        int len=0;
        while(curr){
            len++;
            curr=curr->next;
        }
        if(len==n){
            ListNode* temp=head;
            temp=temp->next;
            head=temp;
            return head;
        }
        int pos=len-n;
        ListNode* prev=head;
        for(int i=1;i<pos;i++){
            prev=prev->next;
        }
        to_delete=prev->next;
        prev->next=prev->next->next;
        delete to_delete;
        return head;
    }
};