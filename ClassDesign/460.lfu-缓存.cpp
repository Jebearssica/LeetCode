/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 *
 * https://leetcode-cn.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (43.74%)
 * Likes:    456
 * Dislikes: 0
 * Total Accepted:    35K
 * Total Submissions: 80.1K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * 请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。
 * 
 * 实现 LFUCache 类：
 * 
 * 
 * LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
 * int get(int key) - 如果键存在于缓存中，则获取键的值，否则返回 -1。
 * void put(int key, int value) -
 * 如果键已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除
 * 最近最久未使用 的键。
 * 
 * 
 * 注意「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。
 * 
 * 为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。
 * 
 * 当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put
 * 操作，使用计数器的值将会递增。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
 * "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 * 输出：
 * [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 * 
 * 解释：
 * // cnt(x) = 键 x 的使用计数
 * // cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
 * LFUCache lFUCache = new LFUCache(2);
 * lFUCache.put(1, 1);   // cache=[1,_], cnt(1)=1
 * lFUCache.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
 * lFUCache.get(1);      // 返回 1
 * ⁠                     // cache=[1,2], cnt(2)=1, cnt(1)=2
 * lFUCache.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
 * ⁠                     // cache=[3,1], cnt(3)=1, cnt(1)=2
 * lFUCache.get(2);      // 返回 -1（未找到）
 * lFUCache.get(3);      // 返回 3
 * ⁠                     // cache=[3,1], cnt(3)=2, cnt(1)=2
 * lFUCache.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
 * ⁠                     // cache=[4,3], cnt(4)=1, cnt(3)=2
 * lFUCache.get(1);      // 返回 -1（未找到）
 * lFUCache.get(3);      // 返回 3
 * ⁠                     // cache=[3,4], cnt(4)=1, cnt(3)=3
 * lFUCache.get(4);      // 返回 4
 * ⁠                     // cache=[3,4], cnt(4)=2, cnt(3)=3
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 最多调用 10^5 次 get 和 put 方法
 * 
 * 
 * 
 * 
 * 进阶：你可以为这两种操作设计时间复杂度为 O(1) 的实现吗？
 * 
 */

// @lc code=start
#include <unordered_map>
using namespace std;
struct Node
{
    int key, val, freq;
    Node *prev, *next;
    Node(int key, int val) : key(key), val(val), freq(1), prev(nullptr), next(nullptr) {}
    Node() : key(0), val(0), freq(1), prev(nullptr), next(nullptr) {}
};
class DoubleLinkList
{
private:
    Node *head, *tail;
    int _size;

public:
    void removeNode(Node *remove)
    {
        remove->prev->next = remove->next;
        remove->next->prev = remove->prev;
        this->_size--;
    }
    void addLastNode(Node *add)
    {
        add->prev = this->tail->prev;
        add->next = this->tail;
        this->tail->prev->next = add;
        this->tail->prev = add;
        this->_size++;
    }
    Node *removeFirstNode()
    {
        Node *first = this->head->next;
        this->removeNode(first);
        return first;
    }
    DoubleLinkList() : _size(0)
    {
        this->head = new Node();
        this->tail = new Node();
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    int size() { return this->_size; }
};
class LFUCache
{
private:
    unordered_map<int, Node *> keyToNode;
    unordered_map<int, DoubleLinkList> freqToList;
    int capacity, minFreq;

public:
    void updateFreqMap(int key)
    {
        Node *changedNode = this->keyToNode[key];
        this->freqToList[changedNode->freq].removeNode(changedNode);
        if (this->freqToList[changedNode->freq].size() == 0 && changedNode->freq == this->minFreq)
            this->minFreq++;
        changedNode->freq++;
        this->freqToList[changedNode->freq].addLastNode(changedNode);
    }
    void removeMinFreqNode()
    {
        Node *minFreqNode = this->freqToList[this->minFreq].removeFirstNode();
        this->keyToNode.erase(minFreqNode->key);
    }
    void addNewNode(int key, int value)
    {
        this->minFreq = 1;
        Node *add = new Node(key, value);
        this->freqToList[1].addLastNode(add);
        this->keyToNode[key] = add;
    }

    LFUCache(int capacity) : capacity(capacity), minFreq(1)
    {
    }

    int get(int key)
    {
        if (keyToNode.find(key) == keyToNode.end())
            return -1;
        this->updateFreqMap(key);
        return this->keyToNode[key]->val;
    }

    void put(int key, int value)
    {
        if (this->capacity > 0)
        {
            if (keyToNode.find(key) == keyToNode.end())
            {
                if (this->capacity == this->keyToNode.size())
                    this->removeMinFreqNode();
                this->addNewNode(key, value);
            }
            else
            {
                this->keyToNode[key]->val = value;
                this->updateFreqMap(key);
            }
        }
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
