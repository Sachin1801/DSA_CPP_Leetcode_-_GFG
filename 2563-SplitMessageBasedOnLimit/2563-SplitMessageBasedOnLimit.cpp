// Last updated: 12/14/2025, 4:16:35 PM
class Solution {
public:
    int dig(int n) {
        int d = 0;
        while(n!=0) {
            n/=10;
            d++;
        }
        return d;
    }
    vector<string> splitMessage(string message, int limit) {
        vector<string> ans;
        vector<int> arr(10000);
        for(int i=0;i<arr.size();i++) arr[i] = i+1;
        int sum = 0, parts = 0;
        for(int i=0;i<arr.size();i++) {
            int n = arr[i];
            sum += dig(n);
            int p = arr[i];
            int total = message.size() + p*3 + dig(n)*p + sum;
            if((int)ceil(total/(limit*1.0))==p) {
                parts = p;
                break;
            }
        }
        int j = 0;
        for(int p=1;p<=parts;p++) {
            int suff = dig(parts) + dig(p) + 3;
            string temp = "";
            int len = limit-suff;
            while(j<message.size()&&len>0) {
                temp += message[j++];
                len--;
            }
            temp += "<";
            temp += to_string(p);
            temp += "/";
            temp += to_string(parts);
            temp += ">";
            ans.push_back(temp);
        }
        return ans;
    }
};