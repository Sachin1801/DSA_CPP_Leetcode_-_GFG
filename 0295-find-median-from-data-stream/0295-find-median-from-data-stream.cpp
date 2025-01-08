class MedianFinder {
private:
    priority_queue<int> leftheap;
    priority_queue<int,vector<int>,greater<int>> rightheap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(leftheap.empty() || leftheap.top() >= num)
            leftheap.push(num);
        else
            rightheap.push(num);
        
        //balance the heap size
        if(leftheap.size() > rightheap.size()+1){
            rightheap.push(leftheap.top());
            leftheap.pop();
        }else if(rightheap.size()> leftheap.size()){
            leftheap.push(rightheap.top());
            rightheap.pop();
        }
    }
    
    double findMedian() {
        if(leftheap.size() > rightheap.size()){
            //oddsize
            return leftheap.top();
        }else{
            return float(leftheap.top()+rightheap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */