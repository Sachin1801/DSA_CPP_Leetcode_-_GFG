class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;
        int lastNum = digits[i];

        if(lastNum != 9) {
            digits[i] +=1 ;
            return digits;
        }
        else{
            while( i>0 && lastNum == 9){
                digits[i]=0;
                i--;
                lastNum = digits[i];
            }
            if(i>0){
                digits[i] += 1;
            }else{
                if(digits[0]==9){
                    digits[0] =0;
                    reverse(digits.begin(),digits.end());
                    digits.push_back(1);
                    reverse(digits.begin(),digits.end());
                }else{
                    digits[0] +=1;
                }
            }
        }
        return digits;
    }
};