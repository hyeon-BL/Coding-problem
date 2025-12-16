Query = []
Chocolates = []
Coffee = []

while True:
    try:
        s = input().split()
        if s[0] == "Query":
            Query.append(int(s[1]))
        elif s[0] == "Chocolate":
            Chocolates.append((int(s[1]), float(s[2])))
        elif s[0] == "Coffee":
            Coffee.append((int(s[1]), float(s[2])))
        if s[0] == "End":
            break
    except EOFError:
        break
    

Query.sort()
Chocolates.sort(key=lambda x: x[0])
Coffee.sort(key=lambda x: x[0])
safe_distance = 0.0

for q in Query:
    for c in Chocolates:
        time_after = q - c[0]
        if time_after >= 0:
            dangerous_area = 8 * c[1] - (time_after / 12)
            safe_distance += max(dangerous_area, 0)
        else:
            break
    for f in Coffee:
        time_after = q - f[0]
        if time_after >= 0:
            dangerous_area = (2 * f[1]) - (time_after ** 2 / 79)
            safe_distance += max(dangerous_area, 0)
        else:
            break

    safe_distance = max(1.0, round(safe_distance, 1))
    print(f"{q} {safe_distance:.1f}")
    safe_distance = 0.0
