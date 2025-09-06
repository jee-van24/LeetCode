/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        Node* curr=head;
        while(curr){
            cout<<curr->val<<"  ";
            temp->next=new Node(curr->val);
            temp=temp->next;
            curr=curr->next;
        }
        unordered_map<Node*,Node*>map;
        curr=head;
        Node* copycurr=dummy->next;
        while(curr){
            map[curr]=copycurr;
            curr=curr->next;
            copycurr=copycurr->next;
        }
        curr=head;
        copycurr=dummy->next;
        while(curr){
            if(curr->random){
                copycurr->random=map[curr->random];
            }
            curr=curr->next;
            copycurr=copycurr->next;
        }
        return dummy->next;
        

    }
};