class RandomizedSet {
private:
    unordered_set<int> unique;
    vector<int> v;
    int size;
public:
    RandomizedSet() {
        size =0;
    }
    
    bool insert(int val) {
        if(v.empty()){
            unique.insert(val);
            v.push_back(val);
            size++;
            return true;
        }else{
            if(unique.find(val) == unique.end()){
                unique.insert(val);
                v.push_back(val);
                size++;
                return true;
            }else{
                return false;
            }
        }
    }
    
    bool remove(int val) {
        if(v.empty()) return false;
        else{
            if(unique.find(val) == unique.end()){
                return false;
            }else{
                unique.erase(val);
                auto it = find(v.begin(),v.end(),val);
                v.erase(it);
                size--;
                return true;
            }
        }
    }
    
    int getRandom() {
        int rand_idx = rand() % size;
        return v[rand_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */