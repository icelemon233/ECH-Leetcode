/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> edges;
        vector<int> indegree;
        edges.resize(numCourses);
        indegree.resize(numCourses);
        for (const auto &prerequisite : prerequisites)
        {
            // edges:某一边有哪些边传入，大小=出度
            edges[prerequisite[1]].push_back(prerequisite[0]);
            // indegree：入度
            indegree[prerequisite[0]]++;
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }

        // 记录遍历了多少个课程
        int visited = 0;
        while (!que.empty())
        {
            visited++;
            // 记录本次出队的课程号
            int course = que.front();
            que.pop();
            for (auto edge : edges[course])
            {
                indegree[edge]--;
                if (indegree[edge] == 0)
                {
                    que.push(edge);
                }
            }
        }
        return visited == numCourses;
    }
};
// @lc code=end
