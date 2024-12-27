//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<string> generateBinaryStrings(int num){
        //Write your code
        if(num==0)
            return {""};
            
        if(num==1)
            return {"0","1"};
            
        vector<string> result;
        for(string s: generateBinaryStrings(num-1)){
            result.push_back(s+"0");
            if(s[s.length()-1]!='1'){
                result.push_back(s+"1");
            }
        }
        return result;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends