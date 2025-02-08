class NumberContainers {

public:
        unordered_map<int,set<int>> mods;
        unordered_map<int,int> m;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        //value introduced for the first time
        if(m.find(index)==m.end()){
            m[index]=number;
            mods[number].insert(index);
        }else{
            //number is already at the index
            int oldnum = m[index];
            m[index]= number;
            mods[oldnum].erase(index);
            mods[number].insert(index);
        }
    }
    
    int find(int number) {
        int val = -1;
        if(mods[number].size() > 0){
            auto it = mods[number].begin();
            val = *it;
        }
        return val;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */