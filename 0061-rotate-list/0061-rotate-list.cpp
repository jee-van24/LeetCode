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
        vector<int>arr;
        if(head==nullptr)return nullptr;
        ListNode* curr=head;
        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        vector<int>temp;
        int n=arr.size();
        k=k%n;
        for(int i=n-k;i<arr.size();i++){
            temp.push_back(arr[i]);
        }
        for(int i=0;i<n-k;i++){
            temp.push_back(arr[i]);
        }
        curr=head;
        int i=0;
        while(curr&&i<temp.size()){
            curr->val=temp[i];
            i++;
            curr=curr->next;
        }
        return head;

    }
};