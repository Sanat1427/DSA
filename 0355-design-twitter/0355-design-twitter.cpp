#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:

    // This will act like a global timestamp
    // Every new tweet gets a bigger time value
    int timer;

    /*
        followMap stores:

        follower -> people he follows

        Example:
        1 -> {2,3}

        means:
        User 1 follows User 2 and User 3
    */
    unordered_map<int, unordered_set<int>> followMap;

    /*
        tweetMap stores all tweets of a user

        user -> list of {time, tweetId}

        Example:
        1 -> [(0,5), (2,10)]

        means:
        at time 0 -> tweet 5
        at time 2 -> tweet 10
    */
    unordered_map<int, vector<pair<int,int>>> tweetMap;

    // Constructor
    Twitter() {
        timer = 0;
    }

    // User posts a tweet
    void postTweet(int userId, int tweetId) {

        /*
            Store:
            {current time, tweetId}

            timer++ means:
            use current timer value first
            then increase it
        */
        tweetMap[userId].push_back({timer++, tweetId});
    }

    // Return latest 10 tweets
    vector<int> getNewsFeed(int userId) {

        vector<int> ans;

        /*
            User should always see his own tweets

            So add himself in follow list
        */
        followMap[userId].insert(userId);

        /*
            Max Heap

            We want MOST RECENT tweet first

            Heap stores:
            {time, tweetId, userId, index}

            Example:
            {7, 15, 2, 3}

            means:
            time = 7
            tweetId = 15
            tweet belongs to user 2
            it is at index 3 in his tweet list
        */
        priority_queue<vector<int>> pq;

        /*
            Put latest tweet of every followee
            into the heap
        */
        for(auto followee : followMap[userId]) {

            // tweets of this followee
            auto &tweets = tweetMap[followee];

            // if user has at least one tweet
            if(!tweets.empty()) {

                // latest tweet is at last index
                int idx = tweets.size() - 1;

                /*
                    Push latest tweet into heap

                    tweets[idx].first  -> time
                    tweets[idx].second -> tweetId
                */
                pq.push({
                    tweets[idx].first,
                    tweets[idx].second,
                    followee,
                    idx
                });
            }
        }

        /*
            Keep taking latest tweet
            until:
            - heap becomes empty
            OR
            - we collect 10 tweets
        */
        while(!pq.empty() && ans.size() < 10) {

            // top = most recent tweet
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int tweetId = curr[1];
            int user = curr[2];
            int idx = curr[3];

            // add tweet to answer
            ans.push_back(tweetId);

            /*
                Now move to older tweet
                of same user

                Example:
                if current index = 5
                next older tweet = 4
            */
            idx--;

            // if older tweet exists
            if(idx >= 0) {

                /*
                    Push older tweet into heap
                */
                pq.push({
                    tweetMap[user][idx].first,
                    tweetMap[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return ans;
    }

    // follower follows followee
    void follow(int followerId, int followeeId) {

        followMap[followerId].insert(followeeId);
    }

    // follower unfollows followee
    void unfollow(int followerId, int followeeId) {

        /*
            Do not allow user
            to unfollow himself
        */
        if(followerId == followeeId)
            return;

        followMap[followerId].erase(followeeId);
    }
};