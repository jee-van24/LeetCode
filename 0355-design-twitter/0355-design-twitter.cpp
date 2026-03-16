class Twitter {
public:
    unordered_map<int,unordered_set<int>>followMap;
    unordered_map<int,vector<pair<int,int>>>tweetMap;
    int time=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto tweet:tweetMap[userId]){
            pq.push(tweet);
        }
        for(auto followee:followMap[userId]){
            for(auto tweet:tweetMap[followee]){
                pq.push(tweet);
            }
        }
        vector<int>res;
        while(!pq.empty()&&res.size()<10){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId)return;
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId)return;
        followMap[followerId].erase(followeeId);
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