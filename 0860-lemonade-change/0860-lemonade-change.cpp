class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> m;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)
                m[bills[i]]++;
            else if(bills[i]==10){
                if(m[5]==0)
                    return false;
                else{
                    m[5]--;
                    m[bills[i]]++;
                }
            }else{
                //20 dollar bill
                if(m[5]==0)
                    return false;
                else if(m[10]==0){
                    if(m[5]<3)
                        return false;
                    else
                        m[5] = m[5]-3;
                }
                else{
                    m[5]--;
                    m[10]--;
                    m[bills[i]]++;
                }
            }
        }
        return true;
    }
};