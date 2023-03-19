/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    // 最简单方法
    // 直接找最左和最右的位置
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // 快速判断
        {
            if (nums.size() == 0)
            {
                return vector<int>({-1, -1});
            }
        }
        // 定义最终返回结果
        int final_left = -1;
        int final_right = -1;
        // 定义第一次查找的左右
        int left = 0, right = nums.size() - 1;
        // 注意right才是可能最左target的左边一个位置
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (target <= nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        final_left = right + 1;
        // 中途判断
        if (final_left == nums.size() || target != nums[final_left])
        {
            return vector<int>({-1, -1});
        }
        else
        {
            // 定义第二次查找的左右
            int left = final_left, right = nums.size() - 1;
            // 注意left才是可能最右target的左边一个位置
            while (left <= right)
            {
                int mid = left + ((right - left) / 2);
                if (target >= nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            final_right = left - 1;
        }
        return vector<int>({final_left, final_right});
    }
};
// @lc code=end

// 思路清晰但繁琐版
// private:
//     // 大前提：只要有相同的数，mid最终一定会在左边

//     // 那么找左边界，就要找mid的左边
//     int get_leftpos(vector<int> &nums, int target)
//     {
//         int left = 0;
//         int right = nums.size() - 1;
//         // 0和-1都被结果占用，设置为-2
//         int leftpos = -2;
//         // 二分法模板
//         while (left <= right)
//         {
//             int mid = left + ((right - left) / 2);
//             if (nums[mid] == target)
//             {
//                 // 继续往左找，不能break，让right缩小
//                 right = mid - 1;
//                 leftpos = right;
//             }
//             else if (nums[mid] > target)
//             {
//                 right = mid - 1;
//             }
//             else
//             {
//                 left = mid + 1;
//             }
//         }
//         return leftpos;
//     }

//     // 找右边界，就要找mid的右边
//     int get_rightpos(vector<int> &nums, int target)
//     {
//         int left = 0;
//         int right = nums.size() - 1;
//         // 0和-1都被结果占用，设置为-2
//         int rightpos = -2;
//         // 二分法模板
//         while (left <= right)
//         {
//             int mid = left + ((right - left) / 2);
//             if (nums[mid] == target)
//             {
//                 // 继续往右找，不能break，让left增大
//                 left = mid + 1;
//                 rightpos = left;
//             }
//             else if (nums[mid] < target)
//             {
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid - 1;
//             }
//         }
//         return rightpos;
//     }

// public:
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         int leftpos = get_leftpos(nums, target);
//         int rightpos = get_rightpos(nums, target);
//         // 三种情况
//         // 1. 不是数组范围内，根据get_leftpos和get_rightpos的设置
//         //     leftpos和rightpos总会有一个是-2
//         if ((leftpos == -2) || (rightpos == -2))
//         {
//             return {-1, -1};
//         }
//         // 2. 能找到,那么左右边界一定相隔大于等于2（大于1）
//         else if (rightpos - leftpos >= 2)
//         {
//             return {leftpos + 1, rightpos - 1};
//         }
//         // 3. 最后一种情况，就是在数组范围内但找不到
//         else
//         {
//             return {-1, -1};
//         }
//     }