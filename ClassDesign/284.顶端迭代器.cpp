/*
 * @lc app=leetcode.cn id=284 lang=cpp
 *
 * [284] 顶端迭代器
 *
 * https://leetcode-cn.com/problems/peeking-iterator/description/
 *
 * algorithms
 * Medium (73.43%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    12.3K
 * Total Submissions: 16.4K
 * Testcase Example:  '["PeekingIterator","next","peek","next","next","hasNext"]\n[[[1,2,3]],[],[],[],[],[]]'
 *
 * 请你设计一个迭代器，除了支持 hasNext 和 next 操作外，还支持 peek 操作。
 * 
 * 实现 PeekingIterator 类：
 * 
 * 
 * 
 * 
 * PeekingIterator(int[] nums) 使用指定整数数组 nums 初始化迭代器。
 * int next() 返回数组中的下一个元素，并将指针移动到下个元素处。
 * bool hasNext() 如果数组中存在下一个元素，返回 true ；否则，返回 false 。
 * int peek() 返回数组中的下一个元素，但 不 移动指针。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
 * [[[1, 2, 3]], [], [], [], [], []]
 * 输出：
 * [null, 1, 2, 2, 3, false]
 * 
 * 解释：
 * PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
 * peekingIterator.next();    // 返回 1 ，指针移动到下一个元素 [1,2,3]
 * peekingIterator.peek();    // 返回 2 ，指针未发生移动 [1,2,3]
 * peekingIterator.next();    // 返回 2 ，指针移动到下一个元素 [1,2,3]
 * peekingIterator.next();    // 返回 3 ，指针移动到下一个元素 [1,2,3]
 * peekingIterator.hasNext(); // 返回 False
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 1000
 * 对 next 和 peek 的调用均有效
 * next、hasNext 和 peek 最多调用  1000 次
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：你将如何拓展你的设计？使之变得通用化，从而适应所有的类型，而不只是整数型？
 * 
 */

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *        struct Data;
 *         Data* data;
 *  public:
 *        Iterator(const vector<int>& nums);
 *         Iterator(const Iterator& iter);
 *
 *         // Returns the next element in the iteration.
 *        int next();
 *
 *        // Returns true if the iteration has more elements.
 *        bool hasNext() const;
 *    };
 */
#include <vector>
using namespace std;

class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

template <class T>
class PeekingIterator : public Iterator<T>
{
private:
    T _next;
    bool _hasNext;

public:
    PeekingIterator(const vector<T> &nums) : Iterator<T>(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        _hasNext = Iterator<T>::hasNext();
        if (_hasNext)
            _next = Iterator<T>::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    T peek()
    {
        return _next;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    T next()
    {
        T ret = _next;
        _hasNext = Iterator<T>::hasNext();
        if (_hasNext)
            _next = Iterator<T>::next();
        return ret;
    }

    bool hasNext() const
    {
        return _hasNext;
    }
};
// @lc code=end
