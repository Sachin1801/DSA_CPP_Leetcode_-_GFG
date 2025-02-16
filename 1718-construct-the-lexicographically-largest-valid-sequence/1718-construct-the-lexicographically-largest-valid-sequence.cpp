class Solution {
public:
    void solve(int index, vector<int>& arr, map<int,bool>& m,int n,bool& found){
        if(index==arr.size()){ //we reach the end ...all numbers    placed
            found = true;
            return;
        }
        if(arr[index]!=-1){ //No space at this index...move ahead
            solve(index+1,arr,m,n,found);
            return;
        }
        // the index is vacant
        for(int i=n; i>=1; i--){ 
            if(m[i]==false){ //To check whether we have placed this number before or not
                if(i!=1 && (index+i)<arr.size() && arr[index+i]==-1){
                    arr[index]=arr[index+i]=i;
                    m[i]= true;
                    solve(index+1,arr,m,n,found);
                    if(found==true){ //EARLY STOPPING ... the catch!
                        return;  
                    }
                    arr[index]=arr[index+i]=-1; //backtrack
                }
                else if(i==1){
                    arr[index] = 1;
                    m[i]= true;
                    solve(index+1,arr,m,n,found);
                    if(found==true){ //EARLY STOPPING.... the catch
                        return;
                    }
                    arr[index] = -1; //backtrack
                }
                m[i] = false; //backtrack
            }
        }
        return;
    }
    vector<int> constructDistancedSequence(int n) {
        int arrSize = 2*n-1; // figure this out!
        vector<int>arr(arrSize,-1);
        map<int,bool>m;
        for(int i = 1; i<=n; i++){
            m.insert({i,false});
        }
        int index = 0;
        bool found = false; // a flag variable we use for early stopping
        solve(index,arr,m,n,found);
        return arr;
    }
};