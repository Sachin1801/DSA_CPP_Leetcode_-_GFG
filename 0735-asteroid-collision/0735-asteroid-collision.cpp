class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int > s;
        for(int i=0;i<asteroids.size();i++){

            //positive right moving asteroid
            if(asteroids[i]>0){
                s.push(asteroids[i]);
            }else{
                //negative / left moving asteroid
                while(!s.empty() && s.top()> 0 && s.top() < abs(asteroids[i]))
                    s.pop();
                if(!s.empty() && s.top()> 0 && s.top() == abs(asteroids[i]))
                    s.pop();
                else if(s.empty() || s.top()<0)
                    s.push(asteroids[i]); 
            }
        }
        
        vector<int> ans(s.size());

        for(int i=s.size()-1;i>=0;i--){
            ans[i]= s.top();
            s.pop();
        }

        return ans;
    }
};