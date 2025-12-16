class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        
        int totalProfit = 0;
        int profit = 0;
        int n = arr.size();
        
        int mini = arr[0];
        for(int i=1;i<n;i++){
            int cost = arr[i] - mini;
            if(cost > profit){
                // cout<<i<<" Profit is "<<profit<<" Cost is :"<<cost<<endl;
                profit = max(profit,cost);
            }else if(cost > 0){
                // cout<<i<<" Profit is "<<profit<<" Cost is :"<<cost<<endl;
                // cout<<"TotalProfit is "<<totalProfit<<endl;
                totalProfit += profit;
                profit = 0;
                mini = arr[i];
            }else{
                totalProfit += profit;
                mini = min(arr[i],mini);
                profit = 0;
            }
            // cout<<"At i: "<<i<< "mini updated to: "<<mini<<endl<<totalProfit<<" "<<profit<<endl;
        }
        totalProfit += profit;
        
        return totalProfit;
        
    }
};