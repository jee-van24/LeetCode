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
        unordered_map<Node*,Node*>map;
        Node* temp=head;
        while(temp){
            Node* newnode=new Node(temp->val);
            map[temp]=newnode;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            Node* copynode=map[temp];
            if(temp->next){
                copynode->next=map[temp->next];
            }
            if(temp->random){
                copynode->random=map[temp->random];
            }
            temp=temp->next;
        }
        return map[head];
    }
};