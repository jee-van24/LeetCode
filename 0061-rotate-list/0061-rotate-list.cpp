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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        if(!head||!head->next)return head;
        vector<int>arr;
        vector<int>nums;
        ListNode* temp=head;
        while(temp){
            len++;
            arr.push_back(temp->val);
            temp=temp->next;

        }
        k=k%len;
        if(k==0)return head;
        cout<<len;
        for(int i=len-k;i<len;i++){
            nums.push_back(arr[i]);
        }
        for(int i=0;i<len-k;i++){
            nums.push_back(arr[i]);
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        for(auto num:nums){
            curr->next=new ListNode(num);
            curr=curr->next;
        }
        return dummy->next;
        
    }
};