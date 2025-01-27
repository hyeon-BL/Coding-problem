str1, str2 = input().split()

difference = 50
for i in range(len(str2)-len(str1)+1):
    count = 0
    for j in range(len(str1)):
        if str1[j] != str2[i+j]:
            count += 1
    difference = min(difference, count)

print(difference)
