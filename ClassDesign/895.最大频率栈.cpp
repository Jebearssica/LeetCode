/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 *
 * https://leetcode-cn.com/problems/maximum-frequency-stack/description/
 *
 * algorithms
 * Hard (54.73%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    7.5K
 * Total Submissions: 13.7K
 * Testcase Example:  '["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"]\n[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]'
 *
 * 实现 FreqStack，模拟类似栈的数据结构的操作的一个类。
 * 
 * FreqStack 有两个函数：
 * 
 * 
 * push(int x)，将整数 x 推入栈中。
 * pop()，它移除并返回栈中出现最频繁的元素。
 * 
 * 如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * 
 * ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
 * [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
 * 输出：[null,null,null,null,null,null,null,5,7,5,4]
 * 解释：
 * 执行六次 .push 操作后，栈自底向上为 [5,7,5,7,4,5]。然后：
 * 
 * pop() -> 返回 5，因为 5 是出现频率最高的。
 * 栈变成 [5,7,5,7,4]。
 * 
 * pop() -> 返回 7，因为 5 和 7 都是频率最高的，但 7 最接近栈顶。
 * 栈变成 [5,7,5,4]。
 * 
 * pop() -> 返回 5 。
 * 栈变成 [5,7,4]。
 * 
 * pop() -> 返回 4 。
 * 栈变成 [5,7]。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 对 FreqStack.push(int x) 的调用中 0 <= x <= 10^9。
 * 如果栈的元素数目为零，则保证不会调用  FreqStack.pop()。
 * 单个测试样例中，对 FreqStack.push 的总调用次数不会超过 10000。
 * 单个测试样例中，对 FreqStack.pop 的总调用次数不会超过 10000。
 * 所有测试样例中，对 FreqStack.push 和 FreqStack.pop 的总调用次数不会超过 150000。
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <stack>
#include <unordered_map>
using namespace std;
class FreqStack
{
private:
    unordered_map<int, int> valToFreq;
    unordered_map<int, stack<int>> freqToVal;
    int maxFreq;

public:
    FreqStack() : maxFreq(0)
    {
    }

    void push(int val)
    {
        this->freqToVal[++this->valToFreq[val]].push(val);
        this->maxFreq = max(this->valToFreq[val], this->maxFreq);
    }

    int pop()
    {
        int curVal = this->freqToVal[this->maxFreq].top();
        this->freqToVal[this->maxFreq].pop();
        this->valToFreq[curVal]--;
        if (this->freqToVal[this->maxFreq].empty())
            this->maxFreq--;
        return curVal;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end
