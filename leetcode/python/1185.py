
class Solution:
    def isLeapYear(self, year: int) -> int:
        if year % 400 == 0 or (year % 100 != 0 and year % 4 == 0):
            return 2
        return 1

    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        Month = [3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3]
        Week = ["Sunday", "Monday", "Tuesday",
                "Wednesday", "Thursday", "Friday", "Saturday"]
        ret = 5
        for eachYear in range(1971, year):
            ret += self.isLeapYear(eachYear)
        for eachMonth in range(0, month - 1):
            ret += Month[eachMonth]
        if month > 2:
            ret += self.isLeapYear(year) - 1
        ret += day - 1
        return Week[ret % 7]


sol = Solution()
print(sol.dayOfTheWeek(3, 1, 1971))
print(sol.dayOfTheWeek(31, 8, 2019))
print(sol.dayOfTheWeek(18, 7, 1999))
print(sol.dayOfTheWeek(15, 8, 1993))
print(sol.dayOfTheWeek(29, 2, 2016))
