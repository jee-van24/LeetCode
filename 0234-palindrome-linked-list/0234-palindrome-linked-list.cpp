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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* newhead=reverse(slow);
        ListNode* temp=head;
        ListNode* temp1=newhead;
        //now we would have the new head as well
        while(temp1!=nullptr){
            if(temp->val!=temp1->val){
                reverse(newhead);
                return false;
            }
            temp=temp->next;
            temp1=temp1->next;
        }
        reverse(newhead);
        return true;
        

    }
    private:
        ListNode* reverse(ListNode* head){
            ListNode* prev=nullptr;
            ListNode* curr=head;
            while(curr!=nullptr){
                ListNode* front=curr->next;
                curr->next=prev;
                prev=curr;
                curr=front;
            }
            return prev;
        }
};