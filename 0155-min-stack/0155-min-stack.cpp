class MinStack {
private:
    stack<pair<int,int>> s;
public:
    MinStack() {
        stack<pair<int,int>> *s = new stack<pair<int,int>>;
    }
    
    void push(int val) {
        if(s.size()==0){
            s.push(make_pair(val,val));
        }else{
            int minele = s.top().second;
            if(val<minele){
                s.push(make_pair(val,val));
            }else{
                s.push(make_pair(val,minele));
            }
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */