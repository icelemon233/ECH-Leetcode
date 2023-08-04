/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 *
 * [1041] 困于环中的机器人
 */

// @lc code=start
class Solution
{
private:
    // 1朝向北，-1朝向南
    int ns_Direction = 1;
    // 1朝向东，-1朝向西
    int we_Direction = 1;
    // 1选择南北方向，-1选择东西方向
    int chooseDirection = 1;

public:
    bool isRobotBounded(string instructions)
    {
        // 机器人执行完指令后，有如下几种情况：
        // 1. 位于原点，陷入循环
        // 2. 不在原点，假设为(x,y)
        // 朝向北，那么下次就会到达(2x,2y)，不陷入循环
        // 朝向南，那么下次仍然会回到原点，陷入循环
        // 朝向东/西，那么经历4次之后仍然会回到原点，陷入循环
        // 最后一种情况如图所示（以朝向西所示）：
        //           第一次
        //   第二次            原点（第四次）
        //           第三次

        int xLoc = 0;
        int yLoc = 0;

        for (char &instruction : instructions)
        {
            if (instruction == 'G')
            {
                if (chooseDirection == 1)
                {
                    yLoc += ns_Direction == 1 ? 1 : -1;
                }
                else
                {
                    xLoc += we_Direction == 1 ? 1 : -1;
                }
            }
            else
            {
                if (instruction == 'L')
                {
                    // 北南转东西
                    if (chooseDirection == 1)
                    {
                        we_Direction = ns_Direction == 1 ? -1 : 1;
                    }
                    // 东西转北南
                    else
                    {
                        ns_Direction = we_Direction == 1 ? 1 : -1;
                    }
                }
                else
                {
                    // 北南转东西
                    if (chooseDirection == 1)
                    {
                        we_Direction = ns_Direction == 1 ? 1 : -1;
                    }
                    // 东西转北南
                    else
                    {
                        ns_Direction = we_Direction == 1 ? -1 : 1;
                    }
                }
                chooseDirection = -chooseDirection;
            }
        }
        if (xLoc == 0 && yLoc == 0)
        {
            return true;
        }
        else
        {
            return (chooseDirection == 1 && ns_Direction == 1) ? false : true;
        }
    }
};
// @lc code=end
