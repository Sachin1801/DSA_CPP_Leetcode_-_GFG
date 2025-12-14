// Last updated: 12/14/2025, 4:16:55 PM
class Solution {

private:
    vector<int> next_greater(const vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> nge(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            nge[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return nge;
    }

    vector<int> prev_greater(const vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> pge(n);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            pge[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pge;
    }

    vector<int> next_smaller(const vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            nse[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return nse;
    }

    vector<int> prev_smaller(const vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> pse(n);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pse;
    }

public:
    long long sumSubarrayMins(const vector<int>& arr) {
        vector<int> nse = next_smaller(arr);
        vector<int> pse = prev_smaller(arr);
        long long total = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total += left * right * (long long)arr[i];
        }

        return total;
    }

    long long sumSubarrayMaxs(const vector<int>& arr) {
        vector<int> nge = next_greater(arr);
        vector<int> pge = prev_greater(arr);
        long long total = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total += left * right * (long long)arr[i];
        }

        return total;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};