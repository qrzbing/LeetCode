#include "global.hpp"

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int len = nums.size();
        int right = 0;   // 跳跃的右边界
        int step = 0;    // 跳跃次数
        int maxJump = 0; // 目前能跳的最远位置

        for (int i = 0; i < len - 1; ++i)
        {
            // 我们不需要访问最后一个元素

            // 在 nums[i] 能跳到的最远位置
            maxJump = max(i + nums[i], maxJump);
            if (i == right) // 要开始新的跳跃了
            {
                right = maxJump;
                step += 1;
            }
        }
        return step;
    }
};

int main()
{
    Solution sol;
    vector<int> v;
    v = {2, 3, 1, 1, 4};
    assert(sol.jump(v) == 2);
    v = {2, 3, 0, 1, 4};
    assert(sol.jump(v) == 2);
    v = {0};
    assert(sol.jump(v) == 0);
    v = {1, 2};
    assert(sol.jump(v) == 1);
    v = {2, 1};
    assert(sol.jump(v) == 1);
    v = {3, 2, 1};
    assert(sol.jump(v) == 1);
    v = {2, 3, 1};
    assert(sol.jump(v) == 1);
    v = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
    cout << sol.jump(v) << endl;
    return 0;
}
