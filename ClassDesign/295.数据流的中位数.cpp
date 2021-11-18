/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 *
 * https://leetcode-cn.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (52.31%)
 * Likes:    576
 * Dislikes: 0
 * Total Accepted:    66.3K
 * Total Submissions: 127K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
 * 
 * 例如，
 * 
 * [2,3,4] 的中位数是 3
 * 
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 * 
 * 设计一个支持以下两种操作的数据结构：
 * 
 * 
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * double findMedian() - 返回目前所有元素的中位数。
 * 
 * 
 * 示例：
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 进阶:
 * 
 * 
 * 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 
 * 
 */

// @lc code=start
#include <queue>
using namespace std;
class MedianFinder
{
private:
    priority_queue<int, vector<int>, less<int>> largeQueue;
    priority_queue<int, vector<int>, greater<int>> smallQueue;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        if (this->largeQueue.size() <= this->smallQueue.size())
        {
            this->smallQueue.push(num);
            this->largeQueue.push(this->smallQueue.top());
            this->smallQueue.pop();
        }
        else
        {
            this->largeQueue.push(num);
            this->smallQueue.push(this->largeQueue.top());
            this->largeQueue.pop();
        }
    }

    double findMedian()
    {
        if (this->largeQueue.size() > this->smallQueue.size())
            return this->largeQueue.top();
        else if (this->largeQueue.size() < this->smallQueue.size())
            return this->smallQueue.top();
        else
            return (this->largeQueue.top() + this->smallQueue.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
