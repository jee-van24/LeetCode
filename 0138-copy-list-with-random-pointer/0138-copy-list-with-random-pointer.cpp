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
    void insertcopyinbetween(Node* head){
        Node* temp=head;
        while(temp){
           Node* nextnode=temp->next;
           Node* copynode=new Node(temp->val);
           copynode->next=nextnode;
           temp->next=copynode;
           temp=nextnode;
        }
    }
    void connectrandom(Node* head){
        Node* temp=head;
        while(temp){
            Node* copynode=temp->next;
            if(temp->random){
                copynode->random=temp->random->next;
            }else{
                copynode->random=nullptr;
            }
            temp=temp->next->next;
        }
    }
    Node* connectnext(Node* head){
        Node* dummy=new Node(-1);
        Node* res=dummy;
        Node* temp=head;
        while(temp){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        insertcopyinbetween(head);
        connectrandom(head);
        Node* newhead=connectnext(head);
        return newhead;
        
    }
};