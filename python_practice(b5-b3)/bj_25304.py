X = int(input())

N = int(input())
sum = 0
for i in range(0,N):
    a, b = map(int, input().split())
    sum += a*b

if(sum == X):
    print("YES")
else:
    print("No") 