class Node{
public:
    int key;
    int val;
    int freq;
    Node* next;
    Node* prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        freq=1;
    }
};

class List{
public:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int size;
    List(){
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    
    void deleteNode(Node* temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        size--;
    }
    
    void addNode(Node* temp){
        temp->next=head->next;
        temp->prev=head;
        head->next->prev=temp;
        head->next=temp;
        size++;
    }
};


class LFUCache : public List {
private:
    unordered_map<int,Node*> mp;
    unordered_map<int,List*> freq_mp;
    int size;
    int leastFreq;
public:
    LFUCache(int capacity) {
        size=capacity;
        leastFreq=0;
    }
    
    void update_freq_mp(Node* temp){
        int freq=temp->freq;
        temp->freq=freq+1;
        freq_mp[freq]->deleteNode(temp);
        if(freq==leastFreq and freq_mp[freq]->size==0){
            leastFreq++;
        }
        List* list=new List();
        if(freq_mp.find(freq+1)!=freq_mp.end()){
            list=freq_mp[freq+1];
        }
        list->addNode(temp);
        freq_mp[freq+1]=list;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            update_freq_mp(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            temp->val=value;
            update_freq_mp(temp);
        }else{
            if(mp.size()==size){
                List* list=freq_mp[leastFreq];
                Node* del=list->tail->prev;
                mp.erase(del->key);
                (*list).deleteNode(del);
                delete del;
            }
            leastFreq=1;
            List* list=new List();
            if(freq_mp.find(leastFreq)!=freq_mp.end()){
                list=freq_mp[leastFreq];
            }
            Node *temp=new Node(key,value);
            list->addNode(temp);
            mp[key]=temp;
            freq_mp[leastFreq]=list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */