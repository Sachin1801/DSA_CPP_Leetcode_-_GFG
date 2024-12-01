class Solution {

private:
    int check(vector<int> &weights, int leastcapacity){
        int load = 0, days =1;
        for(int i=0; i< weights.size();i++){
            if(load + weights[i] <= leastcapacity ){
                load += weights[i];
            }else{
                load = weights[i];
                days++;
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid = (low + high) /2;
            int no_of_days = check(weights,mid);
            if(no_of_days<=days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};