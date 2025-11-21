import sys

remain = sys.stdin.readline().strip()
def find_position(remain):
    index = 0  # Tracks the current position in `remain`

    for number in range(1, 10**6):  # Arbitrary large limit
        num_str = str(number)
        for char in num_str:
            if char == remain[index]:
                index += 1
                if index == len(remain):
                    return number

    return -1  # If the sequence is not found
final = find_position(remain)
print(final)