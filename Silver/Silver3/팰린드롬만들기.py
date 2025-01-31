name = list(input())
name.sort()
alphabet = set(name)
odd = 0
odd_alphabet = ''

for i in alphabet:
    if name.count(i) % 2 == 1:
        odd += 1
        odd_alphabet = i

if odd > 1:
    print("I'm Sorry Hansoo")


else:
    palindrome = ''
    for i in range(len(name)):
        if name.count(name[i]) % 2 == 1:
            palindrome += name[i]
            name.pop(i)
            break
    name.sort(reverse=True)
    for i in range(0, len(name), 2):
        palindrome = name[i] + palindrome + name[i+1]
    print(palindrome)
