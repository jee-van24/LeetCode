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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)return nullptr;
        while(head->val==val){
            ListNode* to_delete=head;
            head=head->next;
            delete to_delete;
            if(head==nullptr)return nullptr;
        }
        ListNode* prev=head;
        ListNode* to_be_deleted=head->next;
        while(to_be_deleted!=nullptr){
            if(to_be_deleted->val==val){
                prev->next=to_be_deleted->next;
                delete to_be_deleted;
                to_be_deleted=prev->next;
            }else{
                prev=to_be_deleted;
                to_be_deleted=to_be_deleted->next;
            }
        }
        return head;
    }
};