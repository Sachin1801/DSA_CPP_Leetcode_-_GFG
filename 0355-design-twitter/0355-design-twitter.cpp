class Twitter {
private:
    unordered_map<int,unordered_set<int>> following;
    unordered_map<int,vector<pair<int,int>> > tweets;

    int timestamp;

    // struct Comparator{
    //     bool operator()(pair<int,int> &p1, pair<int,int> &p2){
    //         return p1.second > p2.second;
    //     }
    // };

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId,timestamp});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](pair<int,int> p1, pair<int,int> p2){
            return p1.second > p2.second;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp) > minHeap(cmp);

        for(auto tweet: tweets[userId]){
            if(minHeap.size()>9){
                minHeap.pop();
            }
            minHeap.push(tweet);
        }

        for(auto followee: following[userId]){
            for(auto tweet: tweets[followee]){
                if(minHeap.size()>9){
                    minHeap.pop();
                }
                minHeap.push(tweet);
            }
        }
        vector<int> ans;
        while(!minHeap.empty()){
            auto temp = minHeap.top();
            minHeap.pop();
            ans.push_back(temp.first);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.find(followerId)!=following.end()){
            following[followerId].erase(followeeId);
            if(following[followerId].empty())
                following.erase(followerId);
        }

    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */