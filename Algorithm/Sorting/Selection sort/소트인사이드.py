import sys
N = list(sys.stdin.readline().strip())
for loop in range(len(N)):
    max_index = loop
    for i in range(loop + 1, len(N)):
        if N[i] > N[max_index]:
            max_index = i
    N[loop], N[max_index] = N[max_index], N[loop]

print("".join(N))