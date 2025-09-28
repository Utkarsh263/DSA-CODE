class Twitter {
private:
    int timeStamp;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> tweets;

public:
    Twitter() {
        timeStamp = 0;
    }

    // Compose a new tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    // Retrieve the 10 most recent tweet ids
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; // (time, tweetId)

        // include user's own tweets
        for (auto &t : tweets[userId]) {
            pq.push(t);
        }

        // include followees' tweets
        for (auto &f : follows[userId]) {
            for (auto &t : tweets[f]) {
                pq.push(t);
            }
        }

        // get top 10
        vector<int> feed;
        int k = 10;
        while (!pq.empty() && k--) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }

    // Follower follows a followee
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // cannot follow self
        follows[followerId].insert(followeeId);
    }

    // Follower unfollows a followee
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
