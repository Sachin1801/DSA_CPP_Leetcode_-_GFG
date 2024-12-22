class Solution {

private:
bool checkIfRotateTrue(string s, string goal ,int off, int n){
    for(int i=0;i<n;i++){
        if(goal[(i+off)%n]!=s[i])
            return false;
    }
    return true;
}

public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(goal[i]==s[0]){
                if(checkIfRotateTrue(s,goal,i,n)==true)
                    return true;
            }
        }
        return false;
    }
};