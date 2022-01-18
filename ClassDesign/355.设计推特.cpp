/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 *
 * https://leetcode-cn.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (40.81%)
 * Likes:    262
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 68.2K
 * Testcase Example:  '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * 设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近 10 条推文。
 * 
 * 实现 Twitter 类：
 * 
 * 
 * Twitter() 初始化简易版推特对象
 * void postTweet(int userId, int tweetId) 根据给定的 tweetId 和 userId
 * 创建一条新推文。每次调用次函数都会使用一个不同的 tweetId 。
 * List<Integer> getNewsFeed(int userId) 检索当前用户新闻推送中最近  10 条推文的 ID
 * 。新闻推送中的每一项都必须是由用户关注的人或者是用户自己发布的推文。推文必须 按照时间顺序由最近到最远排序 。
 * void follow(int followerId, int followeeId) ID 为 followerId 的用户开始关注 ID 为
 * followeeId 的用户。
 * void unfollow(int followerId, int followeeId) ID 为 followerId 的用户不再关注 ID 为
 * followeeId 的用户。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet",
 * "getNewsFeed", "unfollow", "getNewsFeed"]
 * [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
 * 输出
 * [null, null, [5], null, null, [6, 5], null, [5]]
 * 
 * 解释
 * Twitter twitter = new Twitter();
 * twitter.postTweet(1, 5); // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
 * twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
 * twitter.follow(1, 2);    // 用户 1 关注了用户 2
 * twitter.postTweet(2, 6); // 用户 2 发送了一个新推文 (推文 id = 6)
 * twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，id 分别为 -> [6, 5] 。推文
 * id 6 应当在推文 id 5 之前，因为它是在 5 之后发送的
 * twitter.unfollow(1, 2);  // 用户 1 取消关注了用户 2
 * twitter.getNewsFeed(1);  // 用户 1 获取推文应当返回一个列表，其中包含一个 id 为 5 的推文。因为用户 1
 * 已经不再关注用户 2
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= userId, followerId, followeeId <= 500
 * 0 <= tweetId <= 10^4
 * 所有推特的 ID 都互不相同
 * postTweet、getNewsFeed、follow 和 unfollow 方法最多调用 3 * 10^4 次
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
struct Tweet
{
    int tweetId;
    int time;
    Tweet *next;
    Tweet(int id, int time) : tweetId(id), time(time), next(nullptr)
    {
    }
};
class User
{
private:
    int userId;
    unordered_set<int> followed;
    Tweet *head;

public:
    unordered_set<int> getFollowingList()
    {
        return this->followed;
    }
    Tweet *getTweetList()
    {
        return this->head;
    }
    void follow(int followedUserId)
    {
        if (followedUserId != this->userId)
            this->followed.insert(followedUserId);
    }
    void unfollow(int followedUserId)
    {
        if (followedUserId != this->userId && this->followed.count(followedUserId))
            this->followed.erase(followedUserId);
    }
    void post(int tweetId, int time)
    {
        Tweet *add = new Tweet(tweetId, time);
        add->next = this->head;
        this->head = add;
    }
    User(int id) : userId(id), head(nullptr)
    {
    }
    ~User() {}
};
class Twitter
{
private:
    int timeStamp;
    unordered_map<int, User *> idToUser;

public:
    Twitter() : timeStamp(0)
    {
    }

    void postTweet(int userId, int tweetId)
    {
        //check the valid id
        if (!this->idToUser.count(userId))
            this->idToUser[userId] = new User(userId);
        this->idToUser[userId]->post(tweetId, this->timeStamp++);
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        if (!this->idToUser.count(userId))
            return res;
        auto cmp = [](const Tweet *left, const Tweet *right)
        { return left->time < right->time; };
        priority_queue<Tweet *, vector<Tweet *>, decltype(cmp)> pq(cmp);
        auto followingList = this->idToUser[userId]->getFollowingList();
        //insert self tweet
        if (this->idToUser[userId]->getTweetList() != nullptr)
            pq.push(this->idToUser[userId]->getTweetList());
        //insert all head Tweet in following list
        for (int followingId : followingList)
        {
            if (this->idToUser[followingId] == nullptr)
                continue;
            auto head = this->idToUser[followingId]->getTweetList();
            if (head == nullptr)
                continue;
            pq.push(head);
        }
        while (!pq.empty())
        {
            if (res.size() == 10)
                break;
            auto twt = pq.top();
            res.push_back(twt->tweetId);
            pq.pop();
            if (twt->next != nullptr)
                pq.push(twt->next);
        }
        return res;
    }

    void follow(int followerId, int followeeId)
    {
        //check the valid id
        if (!this->idToUser.count(followerId))
            this->idToUser[followerId] = new User(followerId);
        this->idToUser[followerId]->follow(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        //check the valid id
        if (!this->idToUser.count(followerId))
            return;
        this->idToUser[followerId]->unfollow(followeeId);
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
// @lc code=end
