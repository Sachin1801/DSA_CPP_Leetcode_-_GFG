// Last updated: 12/14/2025, 4:15:23 PM
class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1){
            return word;
        }
        int n = word.length();
        int longestPossibleLength = n - (numFriends-1);
        string result;
        queue<pair<char,int>> q;

        //check for largest char
        char ch = word[0];
        for(int i=1;i<n;i++){
            if(word[i] > ch) ch = word[i];
        }
        //store the (char,idx) in the queue
        for(int i =0;i<n;i++){
            if(word[i]==ch){
                q.push({word[i],i});
            }
        }

        //check for the largest string from those index
        while(!q.empty()){
            pair<char,int> p= q.front();
            q.pop();
            int canTake = min(longestPossibleLength, n-p.second);
            string curr = word.substr(p.second, canTake);
            result = max(curr,result);
        }
        return result;


    }
};