class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int s1 = str1.size();
        int s2 = str2.size();
        

        auto divisor = [&](int l){
            if((s1 % l != 0) || (s2 %l != 0)){
                return false;
            }
            
            string sub = str1.substr(0,l);
            int hm1 = s1/l, hm2 = s2/l;
            string repeated1= "", repeated2 ="";
            for(int i=0;i<hm1;i++) repeated1+= sub;
            for(int i=0;i<hm2;i++) repeated2+= sub;
            return str1==repeated1 and str2==repeated2;
        };

        for(int l = min(s1,s2);l>0; l--){
            if(divisor(l))
                return str1.substr(0,l);
        }
        return "";
    }
};