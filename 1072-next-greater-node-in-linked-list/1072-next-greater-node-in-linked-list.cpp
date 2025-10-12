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
        vector<int> res(arr.size(),-1);
        stack<int>s;
        for(int i=arr.size()-1;i>=0;i--){
            if(s.empty()){
                res[i]=0;
            }else{
                while(!s.empty()&&s.top()<=arr[i])s.pop();
                if(s.empty()){
                    res[i]=0;
                }else{
                   res[i]=s.top();
                }
            }
            s.push(arr[i]);
        }
        
        return res;
    }
};