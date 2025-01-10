alphabet = [0]*26
order = 'abcdefghijklmnopqrstuvwxyz'

while 1:
    try:
        s = str(input())

        for i in s:
            if i.isalpha():
                alphabet[ord(i.lower())-97] += 1

    except EOFError:
        break


max_value = max(alphabet)
for i in range(26):
    if alphabet[i] == max_value:
        print(order[i], end="")