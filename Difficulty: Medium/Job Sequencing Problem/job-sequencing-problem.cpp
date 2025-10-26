class Solution {
    private:
        vector<int> parent;
    
        int find(int x){
            if(parent[x]==x ) return x;
            return parent[x]=find(parent[x]);
        }
        
        void merge(int u, int v){
            parent[u]=v;
        }
    
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int,int*>> newProfit(n);
        
        //initialise parent vector
        parent.reserve(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
        for(int i=0;i<n;i++){
            newProfit[i] = {profit[i],&deadline[i]};
        }
        
        //sorting the newProfit based on dec profit
        sort(newProfit.begin(),newProfit.end(),[](pair<int,int*> p1, pair<int,int*> p2){
           return p1.first > p2.first; 
        });
        
        // vector<int> slots(n+1,0);
        int totalJobs = 0;
        int totalProfit = 0;
        for(int i=0;i<n;i++){
            int currDeadline = *(newProfit[i].second);
            int currProfit = newProfit[i].first;
            
            //use disjoint union  
            int availableSlot = find(currDeadline);
            if(availableSlot > 0){
                totalJobs ++;
                totalProfit += currProfit;
                merge(availableSlot, availableSlot-1); //marking that slot as used 
            }
            
        }
        return {totalJobs, totalProfit};
        
    }
};