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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> res;
        for (int i = 0; i < arr.size(); i++) {
            bool flag = false;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] > arr[i]) {
                    res.push_back(arr[j]);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                res.push_back(0);
            }
        }
        return res;
    }
};