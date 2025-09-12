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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* curr = head;
        stack<int> s;
        while (curr) {
            if (s.size() == 2) {
                while (s.size()) {
                    int val = s.top();
                    s.pop();
                    temp->next = new ListNode(val);
                    temp = temp->next;
                }
            }
            s.push(curr->val);
            curr = curr->next;
        }
        while (s.size()) {
            int val = s.top();
            s.pop();
            temp->next = new ListNode(val);
            temp = temp->next;
        }
        return dummy->next;
    }
};