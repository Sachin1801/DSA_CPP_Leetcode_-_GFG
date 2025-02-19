//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
private:

    void solve(int row, int col, vector<vector<int>> &mat, int n, vector<string> &result,
    string current, vector<vector<int>> visited){
        if(row == n-1 && col== n-1){
            result.push_back(current);
            return;
        }
        visited[row][col]=true;
        // 4 direction : up, down, left, right
        //up
        if(row-1>=0 && mat[row-1][col]==1 && !visited[row-1][col]){
            solve(row-1,col,mat,n,result,current+'U',visited);
        }
        //down
        if(row+1 < n && mat[row+1][col]==1 && !visited[row+1][col]){
            solve(row+1,col,mat,n,result,current+'D',visited);
        }
        //left
        if(col-1 >=0 && mat[row][col-1]==1 && !visited[row][col-1]){
            solve(row,col-1,mat,n,result,current+'L',visited);
        }
        if(col+1 < n && mat[row][col+1]==1 && !visited[row][col+1]){
            solve(row,col+1,mat,n,result,current+'R',visited);
        }
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        if(mat[0][0]==0) return {};
        int n = mat.size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        vector<string> result;
        string current="";
        solve(0,0,mat,n,result,current,visited);
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends