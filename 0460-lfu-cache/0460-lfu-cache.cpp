class LFUCache {
public:
    class Node {
    public:
        int key, val, cnt;
        Node* next;
        Node* prev;
        Node(int k, int v) {
            key = k;
            val = v;
            cnt = 1;
            next = prev = nullptr;
        }
    };
    class DLL {
    public:
        Node* head;
        Node* tail;
        int size;
        DLL() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void insertfront(Node* newNode) {
            head->next->prev = newNode;
            newNode->next = head->next;
            head->next = newNode;
            newNode->prev = head;
            size++;
        }
        void detach(Node* delNode) {
            Node* delNext = delNode->next;
            Node* delPrev = delNode->prev;
            delPrev->next = delNext;
            delNext->prev = delPrev;
            size--;
        }
        Node* DelLast() {
            if (size == 0)
                return NULL;
            Node* node = tail->prev;
            detach(node);
            return node;
        }
    };
    unordered_map<int,Node*>KeyTable;
    unordered_map<int,DLL*>FreqTable;
    int minfreq=0,cap=0;
    LFUCache(int capacity) {
        cap=capacity;
        minfreq=0;
    }
    void updatefreq(Node* node){
        int freq=node->cnt;
        DLL* oldlist=FreqTable[freq];
        oldlist->detach(node);
        if(freq==minfreq&&oldlist->size==0){
            minfreq++;
        }
        node->cnt++;
        int newfreq=node->cnt;
        if(!FreqTable.count(newfreq)){
            FreqTable[newfreq]=new DLL();
        }
        FreqTable[newfreq]->insertfront(node);
    }

    int get(int key) {
        int ans=-1;
        if(KeyTable.count(key)){
            ans=KeyTable[key]->val;
            Node* node=KeyTable[key];
            updatefreq(node);
            return ans;
        }
        return ans;
    }


    void put(int key, int value) {
        if(KeyTable.count(key)){
            Node* existing=KeyTable[key];
            existing->val=value;
            updatefreq(existing);
        }else{
            Node* newNode=new Node(key,value);
            if(KeyTable.size()==cap){
                DLL* list=FreqTable[minfreq];
                Node* nodetoremove=list->DelLast();
                KeyTable.erase(nodetoremove->key);
                delete(nodetoremove);
            }
            minfreq=1;
            if(!FreqTable.count(1)){
                FreqTable[1]=new DLL();     
            }
            FreqTable[1]->insertfront(newNode);
            KeyTable[key]=newNode;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */