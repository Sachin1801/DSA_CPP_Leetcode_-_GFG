class Solution {
public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int tot = n + m;
        
        // For median, we need:
        // - If odd total: element at position (tot/2) (0-indexed)
        // - If even total: average of elements at positions (tot/2-1) and (tot/2) (0-indexed)
        
        int i = 0, j = 0;
        int prev = 0, curr = 0;
        
        // We need to iterate until position tot/2 (0-indexed)
        for(int count = 0; count <= tot/2; count++) {
            prev = curr;
            
            // Pick the smaller element from the two arrays
            if(i < n && (j >= m || a[i] <= b[j])) {
                curr = a[i];
                i++;
            } else {
                curr = b[j];
                j++;
            }
        }
        
        // Return median based on odd/even total length
        if(tot % 2 == 1) {
            return (double)curr;
        } else {
            return (double)(prev + curr) / 2.0;
        }
    }
};