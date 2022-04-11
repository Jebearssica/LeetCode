/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 *
 * https://leetcode-cn.com/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (38.50%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 25K
 * Testcase Example:  '["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]\n[[],["hello"],["hello"],[],[],["leet"],[],[]]'
 *
 * 请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。
 *
 * 实现 AllOne 类：
 *
 *
 * AllOne() 初始化数据结构的对象。
 * inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
 * dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key
 * 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
 * getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
 * getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入
 * ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey",
 * "getMinKey"]
 * [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
 * 输出
 * [null, null, null, "hello", "hello", null, "hello", "leet"]
 *
 * 解释
 * AllOne allOne = new AllOne();
 * allOne.inc("hello");
 * allOne.inc("hello");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "hello"
 * allOne.inc("leet");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "leet"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= key.length <= 10
 * key 由小写英文字母组成
 * 测试用例保证：在每次调用 dec 时，数据结构中总存在 key
 * 最多调用 inc、dec、getMaxKey 和 getMinKey 方法 5 * 10^4 次
 *
 *
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct Node
{
    int freq;
    unordered_set<string> keyList;
    Node *prev, *next;
    Node() : freq(0), prev(nullptr), next(nullptr) {}
    Node(int f) : freq(f), prev(nullptr), next(nullptr) {}
    Node(int f, string key) : freq(f), prev(nullptr), next(nullptr)
    {
        this->keyList.insert(key);
    }
};

class AllOne
{
private:
    // from low freq to high
    Node *head, *tail;
    unordered_map<string, Node *> keyToNode;

public:
    AllOne()
    {
        this->head = new Node();
        this->tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key)
    {
        if (keyToNode.count(key))
        {
            auto curNode = keyToNode[key];
            // remove the node from the original list
            curNode->keyList.erase(key);
            auto nextNode = curNode->next;
            if (nextNode == this->tail || nextNode->freq != curNode->freq + 1)
            {
                auto add = new Node(curNode->freq + 1);
                add->next = nextNode;
                add->prev = curNode;
                nextNode->prev = add;
                curNode->next = add;
            }
            curNode->next->keyList.insert(key);
            keyToNode[key] = curNode->next;
            if (curNode->keyList.empty())
            {
                curNode->prev->next = curNode->next;
                curNode->next->prev = curNode->prev;
                delete curNode;
            }
        }
        else
        {
            // add new node at the front of list
            if (this->head->next->freq != 1)
            {
                Node *add = new Node(1);
                add->prev = this->head;
                add->next = this->head->next;
                this->head->next->prev = add;
                this->head->next = add;
            }
            this->head->next->keyList.insert(key);
            keyToNode[key] = this->head->next;
        }
    }

    void dec(string key)
    {
        Node *curNode = keyToNode[key];
        curNode->keyList.erase(key);
        if (curNode->freq == 1)
        {
            keyToNode.erase(key);
        }
        else
        {
            auto prevNode = curNode->prev;
            if (prevNode == this->head || prevNode->freq != curNode->freq - 1)
            {
                auto add = new Node(curNode->freq - 1);
                add->next = curNode;
                add->prev = prevNode;
                prevNode->next = add;
                curNode->prev = add;
            }
            curNode->prev->keyList.insert(key);
            keyToNode[key] = curNode->prev;
        }
        if (curNode->keyList.empty())
        {
            curNode->prev->next = curNode->next;
            curNode->next->prev = curNode->prev;
            delete curNode;
        }
    }

    string getMaxKey()
    {
        auto temp = this->tail->prev;
        for (auto result : temp->keyList)
            return result;
        return "";
    }

    string getMinKey()
    {
        auto temp = this->head->next;
        for (auto result : temp->keyList)
            return result;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
