class Solution {
public:
    int characterReplacement(string s, int k){
    int n = s.length();
    vector<int> vis(26, 0);
    int maxi = 0;
    int maxfreq = 0;

    int i = 0, j = 0;
    while (j < n) {
        vis[s[j] - 'A']++;

        maxfreq = max(maxfreq, vis[s[j] - 'A']);
        if ((j - i + 1) - maxfreq > k) {
            vis[s[i] - 'A']--;
            i++;
        } else {
            maxi = max(maxi, j - i + 1);
        }
        j++;
    }

    return maxi;
}
}
;