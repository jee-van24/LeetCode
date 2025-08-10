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
    ListNode* middleNode(ListNode* head) {
        int len=0;
        ListNode* temp= head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        //now we got the length of the ll
        if(len%2!=0){
            //len is odd then return the l/2th node;
            len=len/2;
            int count=0;
            ListNode* temp=head;
            while(count!=len){
                count++;
                temp=temp->next;
            }
            head=temp;
        }else{
            //its even 
            len=(len+1)/2;
            int count=0;
            ListNode* temp=head;
            while(count!=len){
                count++;
                temp=temp->next;
            }
             head=temp;
        }
        return head;
    }
};