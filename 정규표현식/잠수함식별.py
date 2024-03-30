import re
S = input()
if re.fullmatch(r'((100+1+|01)+)', S):
    print('SUBMARINE')
else:
    print('NOISE')


'''

'''