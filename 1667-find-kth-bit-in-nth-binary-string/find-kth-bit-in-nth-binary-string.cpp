class Solution {
public:

    string invert(string s){
        for(char &c: s){
            if(c=='0')
                c= '1';
            else
                c = '0';
        }
        return s;
    }

    char findKthBit(int n, int k) {
        if(n==1){
            return '0';
        }
        string start = "0";
        // string next;
        for(int i =2;i<=n;i++){
            string inv = invert(start);
            reverse(inv.begin(), inv.end());
            string next = start + '1' + inv;
            start = next;
        }
        return start[k-1];
    }
};