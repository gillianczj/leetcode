class Twitter {
public:
    Twitter() {
        count = 0;
    }
    void postTweet(int userId, int tweetId) {
        fo[userId].insert(userId);
        tw[userId].push_back({count++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto u : fo[userId]) {
            for(auto t : tw[u]) {
                if(pq.empty() || pq.size() < 10) {
                    pq.push(t);
                }else {
                    if(t.first > pq.top().first) {
                        pq.pop();
                        pq.push(t);
                    }
                }
            }
        }
        while(!pq.empty()) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void follow(int followerId, int followeeId) {
        fo[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            fo[followerId].erase(followerId);
        }
    }
private:
    unordered_map<int, unordered_set<int>> fo;
    unordered_map<int, vector<pair<int, int>>> tw;
    int count;
};
