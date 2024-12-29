//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int maxPowerof2(int n) {
        int c = 0;
        while((1<<c) <= n) {  // Changed condition to check power of 2
            c++;
        }
        return c-1;
    }
    
    int countSetBits(int n) {
        if(n == 0) return 0;
        
        int x = maxPowerof2(n);
        // Formula breakdown:
        // 1. x * (1 << (x-1)) -> counts bits for largest power of 2
        // 2. (n - (1 << x) + 1) -> counts MSB for remaining numbers
        // 3. countSetBits(n - (1 << x)) -> recursive call for remaining numbers
        
        return x * (1 << (x-1)) + (n - (1 << x) + 1) + countSetBits(n - (1 << x));
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends