class Solution {
private:
    vector<vector<int> > calc(vector<vector<char>>& matrix) {
        vector< vector<int> >heights(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix[0].size(); i++) {
            int num = matrix[0][i] - '0';
            heights[0][i] = num;
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            for (int i = 1; i < matrix.size(); i++) {
                int num = matrix[i][j] - '0';
                int csum = heights[i - 1][j];
                heights[i][j] = num == 0 ? 0 : csum + 1;
            }
        }
        return heights;
    }

    vector<int> find_nse(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() and arr[s.top()] >= arr[i]) {
                s.pop();
            }
            nse[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return nse;
    }

    vector<int> find_pse(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        vector<int> pse(n);

        for (int i = 0; i < n; i++) {
            while (!s.empty() and arr[s.top()] >= arr[i]) {
                s.pop();
            }
            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = find_nse(heights);
        vector<int> pse = find_pse(heights);
        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            area = max(area, heights[i] * ((nse[i] - pse[i]) - 1));
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector < vector<int> > heights = calc(matrix);
        int ans =0;
        for(int i=0;i<heights.size();i++){
            ans = max(ans, largestRectangleArea(heights[i]));
        }
        return ans;
    }
};