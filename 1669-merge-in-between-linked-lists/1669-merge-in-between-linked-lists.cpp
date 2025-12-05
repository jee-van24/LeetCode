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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        for(int i=0;i<a-1;i++){
            temp=temp->next;
        }
        //now temp will be the node before the one to be unlinked
        ListNode* x=temp->next;
        //now link to the new head
        temp->next=list2;
        temp=x;
        for(int i=a;i<b;i++){
            temp=temp->next;
        }
        ListNode* y=temp->next;
        temp=list1;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=y;
        return list1;
    }
};