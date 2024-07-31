
n = int(input())

arr = [-1,1,2,3] #arr[a] = i 인덱스 a에 i 컵이 있다. 
arr1 = [-1,1,2,3] #arr1[i] = i번 컵의 위치 arr1[1] = 1번컵의 위치
# i,j번 컵의 위치를 바꿀 경우 본래 컵이 위치한 인덱스를 a,b라 하면 -> arr1[i], arr1[j] 
# arr[a] = i, arr[b] = j -> arr[a] = j, arr[b] = i이고
# arr1[i] = a, arr1[j] = b -> arr1[i] = b, arr1[j] = a -> arr1[i] = arr1[j] (바뀌기 전), arr1[j] = arr1[i](바뀌기전)

for z in range(0,n):
    i,j = map(int,input().split(" "))
    beforeIindex = arr1[i] 
    beforeJindex = arr1[j] #1 0
    temp = arr[beforeJindex]
    arr[beforeIindex] = j
    arr[beforeJindex] = i # arr에서 인덱스 0,1값을 바꾼다 => arr[1 2 0]
    temp1 = arr1[i]
    arr1[i] = arr1[j]
    arr1[j] = temp1 #arr1에서 인덱스론 2와 3을 바꿔야한다 

    # print("arr : ",end="")
    # print(arr)
    # print("arr1 : ",end="")
    # print(arr1)

print(arr[1])