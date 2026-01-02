import sys
N = int(sys.stdin.readline())
budgets = list(map(int, sys.stdin.readline().split()))
national_budgets = int(sys.stdin.readline())

start = 0
end = max(budgets)
while start <= end:
    mid = (start + end) // 2

    plan = 0
    for bud in budgets:
        if bud <= mid:
            plan += bud
        else:
            plan += mid
    
    if plan > national_budgets:
        end = mid - 1
    else:
        start = mid + 1

print(start - 1)