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
        unordered_map<int, ListNode*>map;
        int i=0;
        int len=0;
        int res=0;
        for(ListNode* curr=head;curr!=nullptr;curr=curr->next){
            map[i]=curr;
            i++;
            len++;
        }
        cout<<len;
        for(int i=0;i<=len/2-1;i++){
            ListNode* temp1=map[i];
            ListNode* temp2=map[len-i-1];
            int s1=temp1->val;
            int s2=temp2->val;
            res=max(res,s1+s2);
        }
        return res;
    }
};