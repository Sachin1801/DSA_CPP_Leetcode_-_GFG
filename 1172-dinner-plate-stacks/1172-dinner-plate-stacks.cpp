class DinnerPlates {
private:
    vector<stack<int>> v;
    int cap;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    DinnerPlates(int capacity) {
        cap = capacity;
        pq.push(0);
    }

    void push(int val) {
        while(!pq.empty() && (pq.top() >=v.size() || v[pq.top()].size()==cap)) pq.pop();

        int idx ;
        if (!pq.empty()) {
            idx = pq.top();
            pq.pop();
        }else{
            idx = v.size();
            v.push_back(stack<int>());
        }
        v[idx].push(val);
        if(v[idx].size()<cap) pq.push(idx);
    }

    int pop() {
        while(!v.empty() && v.back().empty()) v.pop_back();
        if(v.empty()) return -1;
        int ans = v.back().top();
        v.back().pop();
        if(v.back().size() < cap) pq.push(v.size()-1);
        while(!v.empty() && v.back().empty()) v.pop_back();
        return ans;
    }

    int popAtStack(int index) {
        if(index >= v.size() || v[index].empty()) return -1;

        int ans = v[index].top();
        v[index].pop();
        pq.push(index);
        return ans;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */