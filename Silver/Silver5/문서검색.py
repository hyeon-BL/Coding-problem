import sys
document = sys.stdin.readline().rstrip()
find_str = sys.stdin.readline().rstrip()

indices = []
for idx, char in enumerate(document):
    if char == find_str[0]:
        if document[idx:idx + len(find_str)] == find_str:
            indices.append(idx)

max_count = 0
for start in indices:
    count = 0
    pos = start
    while True:
        pos = document.find(find_str, pos)
        if pos == -1:
            break
        count += 1
        pos += len(find_str)
    if count > max_count:
        max_count = count
print(max_count)