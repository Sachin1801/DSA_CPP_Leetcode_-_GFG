class Solution {
    private:
     bool check(char ch){
        return (ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u');
     }

public:
    int maxVowels(string s, int k) {
        int i = 0;
        int n= s.length();
        int clen = 0;
        int ans = 0;
        queue<char> q;
        while(q.size() < k){
            if(check(s[i])){
                clen++;
            }
            q.push(s[i++]);
        }
        if(clen > ans)
            ans = clen;
        while(i<n){
            char front = q.front();
            q.pop();
            if(check(front))
                clen--;
            if(check(s[i]))
                clen++;
            q.push(s[i++]);
            if(clen > ans)
                ans = clen;
        }
        return ans;    
    }
};