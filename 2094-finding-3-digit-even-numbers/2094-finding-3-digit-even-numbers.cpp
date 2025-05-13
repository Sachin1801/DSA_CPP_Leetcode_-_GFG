class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        for(int i=0;i<digits.size();i++){
            freq[digits[i]]++;
        }
        vector<int> res;
        for(int i=100;i<=998;i+=2){
            int a = i/100, b= (i/10)%10, c=i%10;
            vector<int> temp(10,0);
            temp[a]++;
            temp[b]++;
            temp[c]++;
            bool valid = true;
            for(int j=0;j<10;j++){
                if(temp[j]>freq[j]){
                    valid = false;
                    break;
                }
            }
            if(valid) res.push_back(i);
        }
        return res;
    }
};