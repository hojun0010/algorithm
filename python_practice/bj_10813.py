N,M = map(int,input().split())
result = list()

for i in range(0,N):
    result.append(i+1)

for i in range(0,M):
    i,j = map(int,input().split())
    temp = result[j-1]
    result[j-1] = result[i-1]
    result[i-1] = temp

for i in range(0,len(result)):
    if(i == len(result)-1):
        print(result[i],end="")
        break
    print(result[i],end=" ")
