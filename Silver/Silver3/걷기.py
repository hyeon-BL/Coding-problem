import sys
X, Y, W, S = map(int, sys.stdin.readline().split())
min_cost = float('inf')

if S >= 2 * W:
    # It's cheaper to use only normal moves
    print((X + Y) * W)
    sys.exit(0)

elif S >= W:
    # Use as many diagonal moves as possible, then normal moves
    diag_steps = min(X, Y)
    rem_steps = abs(X - Y)
    total_cost = diag_steps * S + rem_steps * W
    print(total_cost)
    sys.exit(0)

else:
    # S < W, so diagonal moves are cheaper
    diag_steps = min(X, Y)
    rem_steps = abs(X - Y)

    # Case 1: Use diagonal moves for both axes, then normal moves for the remainder
    cost_case1 = diag_steps * S + rem_steps * W
    min_cost = min(min_cost, cost_case1)

    # Case 2: Use diagonal moves for both axes, then use diagonal moves for the remainder (if odd)
    if rem_steps % 2 == 0:
        cost_case2 = (diag_steps + rem_steps) * S
    else:
        cost_case2 = (diag_steps + rem_steps - 1) * S + W
    min_cost = min(min_cost, cost_case2)

    print(min_cost)