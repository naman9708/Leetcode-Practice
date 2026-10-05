class MyHashSet {
public:
 vector<pair<int,int>> arr;
    MyHashSet() {
        
    }
    
    void add(int key) {
        for(int i = 0;i<arr.size();i++){
            if(arr[i].first==key && arr[i].second==1){
                return;
            }
        }
        arr.push_back({key,1});
    }
    
    void remove(int key) {
        for(int i = 0;i<arr.size();i++){
            if(arr[i].first==key && arr[i].second==1){
                arr[i].second=0;
            }
        }
    }
    
    bool contains(int key) {
        for(int i = 0;i<arr.size();i++){
            if(arr[i].first==key && arr[i].second==1){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */