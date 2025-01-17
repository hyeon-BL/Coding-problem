month, day = map(int, input().split())

day_of_week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
day_of_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

sum = 0
for i in range(month - 1):
    sum += day_of_month[i]
sum += day

print(day_of_week[sum % 7])