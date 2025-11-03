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
    ListNode* reversell(ListNode* currhead){
        ListNode* prev=nullptr;
        ListNode* curr=currhead;
        while(curr){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        reverse(arr.begin(),arr.end());
        for(auto n:arr){
            cout<<n<<" ";
        }
        cout<<endl;
        int maxe=INT_MIN;
        ListNode* dummy=new ListNode(0);
        ListNode* dummyhead=dummy;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=maxe){
                dummy->next=new ListNode(arr[i]);
                maxe=max(maxe,arr[i]);
                dummy=dummy->next;
            }
        }
        temp=dummyhead->next;
        dummyhead->next=nullptr;
        delete(dummyhead);
        ListNode* newhead=reversell(temp);
        return newhead;
        
    }
};