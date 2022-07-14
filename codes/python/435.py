from typing import List


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0

        intervals.sort(key=lambda x: x[1])

        n = len(intervals)
        # 首个区间
        right = intervals[0][1]
        ans = 1

        # 对于接下来的区间，选择大于 left 且 right 最小的即可
        for i in range(1, n):
            if intervals[i][0] < right:
                continue
            right = intervals[i][1]
            ans += 1

        # 因为得到的是不重叠区间的数量，因此需要我们减掉。
        return n-ans


if __name__ == '__main__':
    sol = Solution()
