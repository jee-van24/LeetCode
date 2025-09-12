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
    ListNode* reverse(ListNode* head, int left, int right, int len) {
        if (left == 1 && right == len) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while (curr) {
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }
            return prev;
        } else if (left == 1 && right < len) {
            ListNode* curr = head;
            int cnt = 0;
            while (curr) {
                cnt++;
                if (cnt == right) {
                    break;
                }
                curr = curr->next;
            }
            ListNode* nextnode = curr->next;
            curr->next = nullptr;
            ListNode* temp = head;
            curr = head;
            ListNode* prev = nullptr;
            while (curr) {
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }
            temp->next = nextnode;
            return prev;
        } else if (left != 1 && right == len) {
            ListNode* curr = head;
            int cnt = 0;
            while (curr) {
                cnt++;
                if (cnt == left - 1) {
                    break;
                }
                curr = curr->next;
            }
            ListNode* prevnode = curr;
            curr = curr->next;
            prevnode->next = nullptr;
            ListNode* prev = nullptr;
            while (curr) {
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }
            prevnode->next = prev;
            return head;

        } else {
            // in between
            ListNode* curr = head;
            int cnt = 0;
            while (curr) {
                cnt++;
                if (cnt == left - 1) {
                    break;
                }
                curr = curr->next;
            }
            ListNode* prevnode = curr; // got the prevnode
            curr = head;
             cnt = 0;
            while (curr) {
                cnt++;
                if (cnt == right) {
                    break;
                }
                curr = curr->next;
            }
            ListNode* temp=prevnode->next;
            ListNode* tail=temp;
            prevnode->next=nullptr;
            ListNode* nextnode = curr->next;//got the nextnode
            curr->next=nullptr;
            ListNode* prev=nullptr;
            while(temp){
                ListNode* front=temp->next;
                temp->next=prev;
                prev=temp;
                temp=front;
            }
            prevnode->next=prev;
            tail->next=nextnode;
            return head;

        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || !head) {
            return head;
        }
        if (left == 1 && right == 1) {
            return head;
        }
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        head=reverse(head, left, right, len);
        return head;
    }
};