import sys
s, N, K, R1, R2, C1, C2 = map(int, sys.stdin.readline().split())

# compute center region within each N×N block
start = (N - K) // 2
end = start + K  # exclusive


def is_black(r, c):
    for _ in range(s):
        if start <= (r % N) < end and start <= (c % N) < end:
            return True
        r //= N
        c //= N
    return False


out_lines = []
for r in range(R1, R2 + 1):
    row_chars = []
    for c in range(C1, C2 + 1):
        row_chars.append('1' if is_black(r, c) else '0')
    out_lines.append(''.join(row_chars))

sys.stdout.write('\n'.join(out_lines))