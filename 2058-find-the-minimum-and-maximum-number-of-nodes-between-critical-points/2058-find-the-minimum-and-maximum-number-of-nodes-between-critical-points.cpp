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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>indices;
        ListNode* prev=head;
        ListNode* curr=head->next;
        int cnt=0;
        while(curr->next!=nullptr){
            cnt++;
            int frontval=curr->next->val;
            int currval=curr->val;
            int preval=prev->val;
            if(preval>currval&&frontval>currval){
                //minima 
                indices.push_back(cnt);
            }else if(preval<currval&&frontval<currval){
                //maxima
                indices.push_back(cnt);
            }
            
            prev=curr;
            curr=curr->next;
        }
        if(indices.size()<2){
            return {-1,-1};
        }
        int minv=INT_MAX;
        for(int i=1;i<indices.size();i++){
            int temp=abs(indices[i]-indices[i-1]);
            minv=min(minv,temp);
        }
        int maxv=abs(indices[0]-indices[indices.size()-1]);
        return {minv,maxv};
    }
};