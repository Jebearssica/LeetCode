/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 *
 * https://leetcode-cn.com/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (35.94%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 32.2K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 * 给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi]
 * 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。
 * 
 * 如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
 * 输出：true
 * 解释：5 个矩形一起可以精确地覆盖一个矩形区域。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
 * 输出：false
 * 解释：两个矩形之间有间隔，无法覆盖成一个矩形。
 * 
 * 示例 3：
 * 
 * 
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
 * 输出：false
 * 解释：图形顶端留有空缺，无法覆盖成一个矩形。
 * 
 * 示例 4：
 * 
 * 
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
 * 输出：false
 * 解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= rectangles.length <= 2 * 10^4
 * rectangles[i].length == 4
 * -10^5 <= xi, yi, ai, bi <= 10^5
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
template <typename T>
inline void hash_combine(std::size_t &seed, const T &val)
{
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
// auxiliary generic functions to create a hash value using a seed
template <typename T>
inline void hash_val(std::size_t &seed, const T &val)
{
    hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types &...args)
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types &...args)
{
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        return hash_val(p.first, p.second);
    }
};

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        unordered_set<pair<int, int>, pair_hash> nodeMap;
        int right = INT_MIN, left = INT_MAX, down = INT_MAX, up = INT_MIN, sumArea = 0;
        for (vector<int> rec : rectangles)
        {
            //update sum area
            sumArea += (rec[2] - rec[0]) * (rec[3] - rec[1]);

            //update coords
            left = min(left, rec[0]);
            down = min(down, rec[1]);
            right = max(right, rec[2]);
            up = max(up, rec[3]);

            //update the point map, until with only 4 sum rectangle points
            if (nodeMap.count({rec[0], rec[1]}))
                nodeMap.erase({rec[0], rec[1]});
            else
                nodeMap.insert({rec[0], rec[1]});
            if (nodeMap.count({rec[0], rec[3]}))
                nodeMap.erase({rec[0], rec[3]});
            else
                nodeMap.insert({rec[0], rec[3]});
            if (nodeMap.count({rec[2], rec[1]}))
                nodeMap.erase({rec[2], rec[1]});
            else
                nodeMap.insert({rec[2], rec[1]});
            if (nodeMap.count({rec[2], rec[3]}))
                nodeMap.erase({rec[2], rec[3]});
            else
                nodeMap.insert({rec[2], rec[3]});
        }
        //check point map & the sum area & the perfect rectangle's points
        return (nodeMap.size() == 4 && nodeMap.count({left, down}) && nodeMap.count({right, down}) && nodeMap.count({left, up}) && nodeMap.count({right, up}) && sumArea == (up - down) * (right - left));
    }
};
// @lc code=end
