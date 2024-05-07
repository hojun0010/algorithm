N,M = map(int,input().split())

result = list()
for i in range(0,N):
    result.append(0)


for z in range(0,M):
    i,j,k = map(int,input().split())
    for q in range(i,j+1):
        result[q-1] = k

for i in range(len(result)):
    if(i == len(result)-1):
        print(result[i],end="")
        break
    print(result[i],end=" ")
