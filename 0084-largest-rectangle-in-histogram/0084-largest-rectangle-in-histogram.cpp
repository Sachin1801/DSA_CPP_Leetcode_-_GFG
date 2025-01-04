class Solution {
private:

    vector<int> find_nse(vector<int> &arr){
        stack<int> s;
        int n = arr.size();
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and arr[s.top()] >= arr[i]){
                s.pop();
            }
            nse[i]=s.empty() ? n : s.top();
            s.push(i); 
        }
        return nse;
    }

    vector<int> find_pse(vector<int> &arr){
        stack<int> s;
        int n = arr.size();
        vector<int> pse(n);

        for(int i =0 ;i< n; i++){
            while(!s.empty() and arr[s.top()]>= arr[i]){
                s.pop();
            }
            pse[i]= s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pse;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse= find_nse(heights);
        vector<int> pse = find_pse(heights);
        int area = 0;
        for(int i=0;i<heights.size();i++){
            area = max(area, heights[i]*((nse[i]-pse[i])-1));
        }
        return area;
    }
};