// Last updated: 12/14/2025, 4:16:58 PM
class Solution {
private:
    bool canAssign(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        multiset<int> usable_workers(workers.end()-mid,workers.end());
        for(int i=mid-1;i>=0;i--){
            auto currWorker = --usable_workers.end();
            if(*currWorker < tasks[i]){
                if(pills <= 0) return false;

                //Optimal strategy: get the weakest worker to do the task
                auto weakWorker = usable_workers.lower_bound(tasks[i]-strength);
                if(weakWorker==usable_workers.end()) return false;

                pills--;
                usable_workers.erase(weakWorker);
            }else{
                usable_workers.erase(currWorker);
            }
        }
        return true;
    }


public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());    //  O(nlog(n))
        sort(workers.begin(),workers.end()); // O(mlog(m))
        int low =0, high = min(tasks.size(), workers.size());
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canAssign(mid,tasks,workers,pills,strength)){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return high;
    }
};