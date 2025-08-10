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
    ListNode* deleteMiddle(ListNode* head) {
        int len=0;
        if(head==NULL||head->next==NULL)return NULL;
        ListNode* temp= head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        delete temp;
        int mid=len/2;
        ListNode* to_delete=head;
        int cnt=0;
        while(cnt!=mid){
            cnt++;
            to_delete=to_delete->next;
        }
        ListNode* prev=head;
        while(prev->next!=to_delete){
            prev=prev->next;
        }
        prev->next=to_delete->next;
        delete to_delete;
        return head;

    }
};