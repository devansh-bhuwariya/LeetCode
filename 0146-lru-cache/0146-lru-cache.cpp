class Node{
public:
    int key,val;
    Node* next;
    Node* prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
    }
};
class LRUCache{
private:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> mp;
    int size;
public:
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void deleteNode(Node* temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    
    void addNode(Node* temp){
        temp->next=head->next;
        temp->prev=head;
        head->next->prev=temp;
        head->next=temp;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            deleteNode(temp);
            addNode(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            deleteNode(temp);
            addNode(temp);
            temp->val=value;
        }else{
            Node *temp=new Node(key,value);
            if(mp.size()==size){
                Node *del=tail->prev;
                mp.erase(del->key);
                deleteNode(del);
                delete del;
            }
            mp[key]=temp;
            addNode(temp);
        }
    }
};
