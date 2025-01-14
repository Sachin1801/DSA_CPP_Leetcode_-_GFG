class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        if (A.size() == 1)
            return {1};
        unordered_map<int, int> m;
        vector<int> result;
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == B[i]) {
            
            m[A[i]] += 2;
            ans++;
        }
        else {
            m[A[i]]++;
            m[B[i]]++;
            if (m[A[i]] > 1)
                ans++;
            if (m[B[i]] > 1)
                ans++;
        }
        result.push_back(ans);
    }
    return result;
    }
};
