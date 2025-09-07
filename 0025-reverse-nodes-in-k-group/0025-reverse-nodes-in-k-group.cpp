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
    ListNode* getkthnode(ListNode* temp,int k){
        for(int cnt=0;cnt<k-1&&temp;cnt++){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reversell(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevnode=nullptr;
        ListNode* temp=head;
        while(temp){
            ListNode* kthnode=getkthnode(temp,k);
            if(!kthnode){
                if(prevnode){
                    prevnode->next=temp;
                }
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=nullptr;
            ListNode* currhead=reversell(temp);
            if(!prevnode){
                head=kthnode;
            }else{
                prevnode->next=currhead;
            }
            prevnode=temp;
            temp=nextnode;
        }
        return head;
    }
};