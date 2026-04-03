class Twitter {
public:
    int time = 0;

    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        
        vector<int> result;

        // Max heap: (time, tweetId, userId, index)
        priority_queue<vector<int>> pq;

        // Ensure user follows themselves
        follows[userId].insert(userId);

        // Push latest tweet of each followee
        for(int user : follows[userId]) {
            if(tweets[user].size() > 0) {
                int idx = tweets[user].size() - 1;
                auto &t = tweets[user][idx];
                pq.push({t.first, t.second, user, idx});
            }
        }

        // Get top 10 tweets
        while(!pq.empty() && result.size() < 10) {
            auto top = pq.top();
            pq.pop();

            int time = top[0];
            int tweetId = top[1];
            int user = top[2];
            int idx = top[3];

            result.push_back(tweetId);

            // Push next older tweet
            if(idx > 0) {
                auto &t = tweets[user][idx - 1];
                pq.push({t.first, t.second, user, idx - 1});
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};