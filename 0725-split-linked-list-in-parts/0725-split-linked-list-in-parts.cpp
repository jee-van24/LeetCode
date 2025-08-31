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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        vector<ListNode*>res;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        int limit=len/k;
        int extra=len%k;
        ListNode* currhead=head;
        for(int i=0;i<k;i++){
            int currsize=limit;
            if(extra>0){
                currsize++;
                extra--;
            }
            if(currsize==0){
                res.push_back(nullptr);
                continue;
            }
            res.push_back(currhead);
            ListNode* currtail=currhead;
            for(int j=1;j<currsize;j++){
                currtail=currtail->next;
            }
            ListNode* nexthead=currtail->next;
            currtail->next=nullptr;
            currhead=nexthead;

        }
        return res;  
    }
};