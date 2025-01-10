low_upp_num_blank = [0]*4


while 1:
    try:
        s = str(input())

        for i in s:
            if i.islower():
                low_upp_num_blank[0] += 1
            elif i.isupper():
                low_upp_num_blank[1] += 1
            elif i.isdigit():
                low_upp_num_blank[2] += 1
            elif i.isspace():
                low_upp_num_blank[3] += 1
        else:
            print(*low_upp_num_blank)
            low_upp_num_blank = [0]*4

    except EOFError:
        break

