class LRUCache {
public:
    int sizze;
    list<pair<int,int>> lru;
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        sizze = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        auto it = mp[key];
        int value = it->second;
        lru.erase(it);
        lru.push_front({key, value});
        mp[key] = lru.begin();

        return value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            lru.erase(mp[key]);
        } 
        else if (lru.size() == sizze) {
            auto last = lru.back();
            mp.erase(last.first);
            lru.pop_back();
        }

        lru.push_front({key, value});
        mp[key] = lru.begin();
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(sizze);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */