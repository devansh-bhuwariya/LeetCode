class LFUCache {
public:
    unordered_map<int,list<pair<int,int>>> freq;
    unordered_map<int,pair<int,list<pair<int,int>>::iterator>>cache;
    int cap;
    int min_freq;
    LFUCache(int capacity) {
        cap=capacity;
        min_freq=0;
    }
    void insert(int key,int frequency,int value){
        freq[frequency].push_back({key,value});
        cache[key]={frequency,--freq[frequency].end()};
    }
    int get(int key) {
        const auto it=cache.find(key);
        if(it==cache.end()) return -1;
        int f= it->second.first;
        auto iter=it->second.second;
        const pair<int,int> kv=*iter;
        freq[f].erase(iter);
        if(freq[f].empty()){
            freq.erase(f);
            if(min_freq==f){
                min_freq++;
            }
        }
        insert(key,f+1,kv.second);
        return kv.second;
    }
    
    void put(int key, int value) {
        if(cap<=0) return;
        auto it=cache.find(key);
        if(it!=cache.end()){
            it->second.second->second=value;
            get(key);
            return ;
        }
        if(cap==cache.size()){
            cache.erase(freq[min_freq].front().first);
            freq[min_freq].pop_front();
            if(freq[min_freq].empty()){
                freq.erase(min_freq);
            }
        }
        min_freq=1;
        insert(key,1,value);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */