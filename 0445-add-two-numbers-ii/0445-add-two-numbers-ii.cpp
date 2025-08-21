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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Convert l1 -> string
        string str1;
        while (l1 != nullptr) {
            str1.push_back('0' + l1->val);
            l1 = l1->next;
        }

        // Convert l2 -> string
        string str2;
        while (l2 != nullptr) {
            str2.push_back('0' + l2->val);
            l2 = l2->next;
        }

        int i = str1.size() - 1;
        int j = str2.size() - 1;
        int carry = 0;
        stack<int> s;

        // Step 1: add digit by digit from right to left
        while (i >= 0 || j >= 0 || carry > 0) {
            int d1 = 0;
            if (i >= 0) {
                d1 = str1[i] - '0';
                i--;
            }

            int d2 = 0;
            if (j >= 0) {
                d2 = str2[j] - '0';
                j--;
            }

            int sum = d1 + d2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            s.push(digit);  // keep in reverse order
        }

        // Step 2: build linked list from stack
        ListNode* newhead = nullptr;
        ListNode* tail = nullptr;

        while (!s.empty()) {
            ListNode* curr = new ListNode(s.top());
            s.pop();

            if (!newhead) {
                newhead = curr;
                tail = curr;
            } else {
                tail->next = curr;
                tail = curr;
            }
        }

        return newhead;
    }
};
