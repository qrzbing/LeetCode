

Month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def isLeapYear(year: int) -> bool:
    if year % 400 == 0 or (year % 100 != 0 and year % 4 == 0):
        return True
    return False


def getDaysFrom19710101(year: int, month: int, day: int) -> int:
    days = 0
    for eachYear in range(1971, year):
        print(eachYear)
        if isLeapYear(eachYear):
            days += 366
        else:
            days += 365
    for eachMonth in range(0, month - 1):
        print(eachMonth + 1)
        days += Month[eachMonth]
    if isLeapYear(year) and month > 2:
        days += 1
    return days + day - 1


if __name__ == '__main__':
    days = getDaysFrom19710101(1993, 8, 15)
    days = getDaysFrom19710101(1999, 7, 18)
    # days = getDaysFrom19710101(1971, 1, 3)
    # (19930815-19710101)%7=0
    day = 7 + 0 - days % 7
    print(day)  # 5 -> Friday
