#define ll long long

class ProductOfNumbers {
    private:
    vector<ll> container;
    
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        container.push_back((long long)num);
    }
    
    int getProduct(int k) {
        int n = container.size();
        long long ans=1;
        for(int i = n-1; i >=n-k;i--){
            ans*=container[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */