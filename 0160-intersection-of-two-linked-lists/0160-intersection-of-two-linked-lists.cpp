/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>seen;
        ListNode* temp=headA;
        while(temp){
            seen.insert(temp);
            temp=temp->next;
        }
        temp=headB;
        while(temp){
            if(seen.find(temp)!=seen.end()){
                return temp;
            }
            temp=temp->next;
        }
        return nullptr;
    }
};