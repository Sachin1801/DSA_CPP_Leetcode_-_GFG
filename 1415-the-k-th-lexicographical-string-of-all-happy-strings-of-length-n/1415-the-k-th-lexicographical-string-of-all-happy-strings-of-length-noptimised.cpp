class Solution {
private:
    vector<string> happyStrings;

    void generateHappyStrings(int n, string current){
        if(current.size()==n){
            happyStrings.push_back(current);
            return;
        }

        for(char ch: {'a','b','c'}){
            if(current.empty() || current.back()!=ch){
                generateHappyStrings(n,current+ch);
            }
        }
    }

public:
    string getHappyString(int n, int k){
        if(k > 3*pow(2,n-1)) return "";
        string current="";
        generateHappyStrings(n,current);
        if(k > happyStrings.size()) return "";
        return happyStrings[k-1];
    }
};