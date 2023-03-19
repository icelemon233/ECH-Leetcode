/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        // 前缀和加二分法
        vector<int> ret;
        sort(nums.begin(), nums.end());
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        // 前缀和
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        // 二分查找
        for (int &query : queries)
        {

            int left = 0;
            int right = prefix.size() - 1;
            int mid = 0;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                if (query < prefix[mid])
                {
                    right = mid - 1;
                }
                else if (query > prefix[mid])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid + 1;
                    break;
                }
            }
            ret.emplace_back(left > right ? right + 1 : right);
        }
        return ret;
    }
};
// @lc code=end
