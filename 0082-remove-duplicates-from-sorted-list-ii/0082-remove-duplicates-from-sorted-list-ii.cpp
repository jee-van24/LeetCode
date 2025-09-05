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
    ListNode* deleteDuplicates(ListNode* head) {
        
        unordered_map<int,int>map;
        ListNode* temp=head;
        while(temp){
            map[temp->val]++;
          
            temp=temp->next;
        }
        vector<int>arr;
        for(auto &pair:map){
            if(pair.second==1){
                arr.push_back(pair.first);
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int i=0;
        while(i<arr.size()){
            curr->next=new ListNode(arr[i]);
            curr=curr->next;
            i++;
        }
        return dummy->next;
    }
};