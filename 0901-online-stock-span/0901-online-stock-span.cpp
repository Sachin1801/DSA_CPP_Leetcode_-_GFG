class StockSpanner {
private: 
    stack<pair<int,int> > *s;

public:
    StockSpanner() {
        s = new stack<pair<int,int>> ;
    }
    
    int next(int price) {
        int cnt =1;
        while(!s->empty() and s->top().first <= price){
            cnt += s->top().second;
            s->pop();
        }
        s->push({price,cnt});
        return s->top().second;
    }

    ~StockSpanner(){
        delete s;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */