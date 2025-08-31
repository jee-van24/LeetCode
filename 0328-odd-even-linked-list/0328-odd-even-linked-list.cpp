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
        vector<int>res;
        ListNode* temp=head;
        if(!head)return nullptr;
        //collect all the values at the odd idx
        while(temp){
            res.push_back(temp->val);
            if(temp->next){
                temp=temp->next->next;
            }else{
                break;
            }
            
        }
        //now collect the values at even idx 
        temp=head->next;
        while(temp){
            res.push_back(temp->val);
            if(temp->next){
                temp=temp->next->next;
            }else{
                break;
            }
            
        }
        temp=head;
        for(auto num:res){
            temp->val=num;
            temp=temp->next;
        }
        return head;
    }
};