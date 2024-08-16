class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    
    }
    
    void addNode(Node* n){
        head->next->prev=n;
        n->next=head->next;
        head->next=n;
        n->prev=head;
    }
    
    void deleteNode(Node* n){
        n->next->prev=n->prev;
        n->prev->next=n->next;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* n=mp[key];
        deleteNode(n);
        addNode(n);
        return n->val;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            Node* n=new Node(key,value);
            if(mp.size()==cap){
                Node* del=tail->prev;
                mp.erase(del->key);
                deleteNode(del);
                delete del;
                
            }
            mp[key]=n;
            addNode(n);
        }else{
            Node* n=mp[key];
            n->val=value;
            deleteNode(n);
            addNode(n);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */