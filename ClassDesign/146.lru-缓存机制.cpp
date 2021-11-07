/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (52.59%)
 * Likes:    1708
 * Dislikes: 0
 * Total Accepted:    245.8K
 * Total Submissions: 468K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
 * 
 * 
 * 
 * 实现 LRUCache 类：
 * 
 * 
 * LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value)
 * 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 0 
 * 最多调用 2 * 10^5 次 get 和 put
 * 
 * 
 */

// @lc code=start
#include <unordered_map>
using namespace std;
class Node
{
public:
    int key, val;
    Node *next, *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr)
    {
    }
};
class DoubleLinkList
{
private:
    Node *head, *tail;
    int _size;

public:
    DoubleLinkList()
    {
        this->head = new Node(0, 0);
        this->tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        this->_size = 0;
    }
    void addLastNode(Node *add)
    {
        add->prev = this->tail->prev;
        add->next = this->tail;
        this->tail->prev->next = add;
        this->tail->prev = add;
        this->_size++;
    }
    void removeNode(Node *remove)
    {
        remove->prev->next = remove->next;
        remove->next->prev = remove->prev;
        this->_size--;
    }
    Node *removeFirstNode()
    {
        if (this->_size == 0)
            return nullptr;
        else
        {
            Node *first = this->head->next;
            this->removeNode(first);
            return first;
        }
    }
    int size()
    {
        return this->_size;
    }
};
class LRUCache
{
private:
    unordered_map<int, Node *> map;
    DoubleLinkList cache;
    int capacity;

    void updateUsedTable(int key)
    {
        Node *usedNode = this->map[key];
        this->cache.removeNode(usedNode);
        this->cache.addLastNode(usedNode);
    }
    void addNode(int key, int val)
    {
        Node *add = new Node(key, val);
        this->cache.addLastNode(add);
        this->map[key] = add;
    }
    void deleteNode(int key)
    {
        Node *del = this->map[key];
        this->cache.removeNode(del);
        this->map.erase(key);
    }
    void deleteLRUNode()
    {
        Node *LRUNode = this->cache.removeFirstNode();
        this->map.erase(LRUNode->key);
    }

public:
    LRUCache(int capacity) : capacity(capacity)
    {
    }

    int get(int key)
    {
        if (this->map.find(key) == this->map.end())
            return -1;
        else
        {
            this->updateUsedTable(key);
            return this->map[key]->val;
        }
    }

    void put(int key, int value)
    {
        if (this->map.find(key) == this->map.end())
        {
            if (this->capacity == this->cache.size())
                this->deleteLRUNode();
            this->addNode(key, value);
        }
        else
        {
            this->deleteNode(key);
            this->addNode(key, value);
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
