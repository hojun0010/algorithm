
result = []
while(True):
    input1 = []
    input1 = list(map(int,input().split()))
    if (input1[0] == 0):
        break

    else:
        a = input1[0]
        input2 = input1[1:]
        # print(input2)
        res = 1
        for i in range(0,2*a,2):
            sf = input2[0]
            sl = input2[1]
            del input2[0]
            del input2[0]
            res *= sf
            res -= sl
        result.append(res)

for i in result:
    print(i)