//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{

private:
    void MaxHeapify(vector<int> &arr, int i , int n){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;
        if(left<n && arr[left] > arr[largest])
            largest = left;
        if(right < n && arr[right] > arr[largest])
            largest = right;
        if(largest != i){
            swap(arr[i],arr[largest]);
            MaxHeapify(arr,largest,n);
        }
        return;
    }
    
public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for(int i = (N-2)/2; i>=0;i--){
            MaxHeapify(arr,i,N);
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends