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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        vector<int>arr;
        if(k==1)return head;
        if(head->next==nullptr)return head;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int len=arr.size();
        for(int i=0;i+k<=len;i+=k){
            reverse(arr.begin()+i,arr.begin()+i+k);
        }
        ListNode* newhead=nullptr;
        ListNode* tail=nullptr;
        for(auto val:arr){
            ListNode* curr=new ListNode(val);
            if(!newhead){
                newhead=curr;
                tail=curr;
            }else{
                tail->next=curr;
                tail=curr;
            }
        }
        return newhead;

    }
};