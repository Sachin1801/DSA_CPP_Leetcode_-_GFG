class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            switch(ch){
                case 'C':
                    if(i+1<s.length()){
                        if(s[i+1]!='D' and s[i+1]!='M'){
                            ans += 100;
                        }else if(s[i+1]=='D'){
                            ans+= 400;
                            i++;
                        }else{
                            ans += 900;
                            i++;
                        }
                    } 
                    else{
                        ans+=100;
                    }
                    break;
                case 'I':
                    if(i+1<s.length()){
                        if(s[i+1]!='V' and s[i+1]!='X'){
                            ans += 1;
                        }else if(s[i+1]=='V'){
                            ans+= 4;
                            i++;
                        }else{
                            ans += 9;
                            i++;
                        }
                    }else{
                        ans += 1;
                    }
                    break;
                case 'X':
                    if(i+1<s.length()){
                        if(s[i+1]!='L' and s[i+1]!='C'){
                            ans += 10;
                        }else if(s[i+1]=='L'){
                            ans+= 40;
                            i++;
                        }else{
                            ans += 90;
                            i++;
                        }
                    }else{
                        ans += 10;
                    }
                    break;
                case 'M':
                    ans+= 1000;
                    break;
                case 'V':
                    ans += 5;
                    break;
                case 'D':
                    ans += 500;
                    break;
                case 'L':
                    ans += 50;
                    break; 

            }
        }
        return ans;
    }
};