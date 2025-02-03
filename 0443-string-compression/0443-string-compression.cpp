class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1)
            return 1;
        int read = 0;
        int write =0;
        while(read<chars.size()){
            char currch = chars[read];
            int count = 0;

            while(read<chars.size() && chars[read]==currch){
                read++;
                count++;
            }
            chars[write++]=currch;

            if(count > 1){
                for(auto ch: to_string(count)){
                    chars[write++]=ch;
                }
            }
        }
        return write;
    }
};