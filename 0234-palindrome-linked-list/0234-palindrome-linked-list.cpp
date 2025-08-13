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
        ListNode* temp=head;
        stack<int>s;
        while(temp!=nullptr){
            s.push(temp->val);
            temp=temp->next;
        }
        ListNode* newhead=nullptr;
        ListNode* tail=nullptr;
        while(s.size()){
            int val=s.top();
            s.pop();
            ListNode* node=new ListNode(val);
            if(!newhead){
                newhead=node;
                tail=node;
            }else{
                tail->next=node;
                tail=node;
            }
        }
        ListNode* temp1=head;
        ListNode* temp2=newhead;
        bool flag=true;
        while(temp1&&temp2){
            if(temp1->val==temp2->val){
                temp1=temp1->next;
                temp2=temp2->next;
            }else{
                flag=false;
                break;
            }
        }
        if(flag){
            return true;
        }
        return false;  
    }
};