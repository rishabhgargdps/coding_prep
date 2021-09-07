class Twitter
{
public:
    /** Initialize your data structure here. */
    int timestamp = 0;
    unordered_map<int, unordered_set<int>> followed;
    unordered_map<int, unordered_map<int, int>> tweets;

    Twitter()
    {
        timestamp = 0;
        followed.clear();
        tweets.clear();
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        tweets[userId].insert({timestamp, tweetId});
        timestamp++;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<pair<int, int>> recent;
        for (auto itr = tweets[userId].begin(); itr != tweets[userId].end(); ++itr)
        {
            recent.push_back({itr->first, itr->second});
        }
        for (auto itr = followed[userId].begin(); itr != followed[userId].end(); ++itr)
        {
            for (auto itr2 = tweets[*itr].begin(); itr2 != tweets[*itr].end(); ++itr2)
            {
                recent.push_back({itr2->first, itr2->second});
            }
        }
        sort(recent.begin(), recent.end(), [](pair<int, int> x, pair<int, int> y)
             {
                 if (x.first == y.first)
                     return x.second < y.second;
                 return x.first > y.first;
             });
        vector<int> res;
        int k = recent.size();
        int n = min(k, 10);
        for (int i = 0; i < n; i++)
        {
            res.push_back(recent[i].second);
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        followed[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        followed[followerId].erase(followeeId);
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