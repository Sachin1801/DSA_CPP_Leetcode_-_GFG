class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        /*int beg = 0;
        int len = 0;
        int maxlen = 0;
        unordered_set<char> st;

        for(int i = 0; i < s.length(); i++){
            if(st.find(s[i]) != st.end()){
                maxlen = max(len, maxlen);
                len--;
                st.erase(s[beg]);
                beg = beg + 1;
                i--;
            }
            else{
                st.insert(s[i]);
                len++;
            }
        }
        return max(len, maxlen);;
    }*/
	if(s.empty())
		return 0;
	
	int len = 0;
	
	vector<int> vec(256,-1);
	int left = 0;
	int right = 0;
	
	
	while(right < s.length()){
		if(vec[s[right]] != -1){
			left = max(left , vec[s[right]]+1);
		}
		len = max(len, right-left+1);
		vec[s[right]] = right;
		right++;
	
	}
	return len;	
    }
        
};
