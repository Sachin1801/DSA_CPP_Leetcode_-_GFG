

class MyStack {
    private:
        queue<int> q1;
        queue<int> q2;
public:
    MyStack() {
        queue<int> *q1 = new queue<int>;
        queue<int> *q2 = new queue<int>;
    }
    
    void push(int x) {
        if(q1.size()==0){
            q1.push(x);
        }
        else{
                q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.swap(q2);
        }
    }
    
    int pop() {
        int top = q1.front();
        if(!q1.empty()){
            q1.pop();
        }
        return top;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */