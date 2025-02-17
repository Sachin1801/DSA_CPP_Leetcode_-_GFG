class Solution {
public:
    int ans=0;
    
    void solve(int freq[])
    {
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            {
                freq[i]--;
                ans++;
                solve(freq);
                freq[i]++;
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        int freq[26]={0};
        for(int i=0;tiles[i]!='\0';i++)
        {
            // int idx = tiles[i]-'A';
            freq[tiles[i]-'A']++;
        }
        solve(freq);
        return ans;
    }
};