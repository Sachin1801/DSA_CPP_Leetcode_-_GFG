//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    int getith(int num, int i){
        return (num>>(i-1))&1;
    }
    
    int Setith(int num, int i){
        return num | (1<<(i-1));
    }
    
    int Clearith(int num ,int i){
        return num & (~(1<<(i-1))) ;
    }
    
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int ith = getith(num,i);
        
        int setith = Setith(num ,i);
        
        int clearith = Clearith(num , i);
        
        cout<< ith<<" "<<setith << " "<<clearith<<" "; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends