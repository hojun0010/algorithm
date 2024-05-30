

# 최소의 연산의 횟수, n개의 번호를 빼네는 데 있어 이전의 번호 찾기 방식이 후의 번호를 빼네는데 있어 영향을 미치는가?
# 문제가 되지 않는다 -> why? 번호를 빼네는 데 있어 필요한 연산은 왼쪽이동 or 오른쪽 이동 밖에 없으므로 

def findMin(n, index_arr):
    result = 0
    for i in range(0, len(index_arr)):
        if(index_arr[i] == 1): 
            n -= 1
            for j in range(i,len(index_arr)):
                index_arr[j] -= 1
        elif(index_arr[i] <= n//2+1): #moveLeft
            # print(i,"번째 왼쪽이동 횟수 추가 : ",index_arr[i]-1)
            result += index_arr[i]-1
            n -= 1
            for j in range(i+1,len(index_arr)):
                index_arr[j] -= index_arr[i]
                if(index_arr[j] <= 0): index_arr[j] += n+1
        else: #moveRight
            # print(i,"번째 오른쪽이동 횟수 추가 : ",n-index_arr[i]+1)
            cnt = n-index_arr[i]+1
            result += cnt
            n -= 1
            for j in range(i+1,len(index_arr)):
                index_arr[j] = index_arr[j]+cnt-1 if index_arr[j] < index_arr[i] else index_arr[j] - index_arr[i]
        index_arr[i] = 0
        # print(index_arr)
    return result
n,m = map(int, input().split(" "))
index_arr = list(map(int, input().split(" ")))

print(findMin(n,index_arr))