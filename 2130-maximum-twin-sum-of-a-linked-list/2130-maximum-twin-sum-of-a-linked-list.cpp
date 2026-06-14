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
    int pairSum(ListNode* head) {
        vector<int>arr;
        ListNode* curr=head;
        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        int res=0;
        for(int i=0;i<arr.size()/2;i++){
            int sum=arr[i]+arr[arr.size()-i-1];
            res=max(res,sum);
        }
        return res;
    }
};