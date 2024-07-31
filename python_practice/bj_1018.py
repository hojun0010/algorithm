
m,n = map(int, input().split(" "))
comp1 = [['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 
'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']]
comp2 = [['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 
'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']]

arr = list()
for i in range(0,m):
    arr.append(list(input())) 

min = 64
cnt1 = 0
cnt2 = 0

for i in range(0,m-7): # m = 10 [0,1,2]
    for j in range(0,n-7): #정사각형이 처음 시작하는 점 n = 13 [0,1,2,3,4,5]
        cnt1 = 0
        cnt2 = 0
        for k in range(i,i+8):
            for q in range(j, j+8): # 시작점이 정해진후 고정된 8x8 범위를 탐색하는 반복문
                cnt1 = cnt1+1 if arr[k][q] == comp1[k-i][q-j] else cnt1
                cnt2 = cnt2+1 if arr[k][q] == comp2[k-i][q-j] else cnt2
        cnt_min = cnt1 if cnt1 < cnt2 else cnt2
        min = cnt_min if cnt_min < min else min
        
print(min)


# 나의 풀이 방법은 모든 경우를 탐색
# https://ittrue.tistory.com/60 8x8 영역을 칠할때 두가지 경우(시작점이 흰색인 경우와 검은색인 경우)로 나누어 arr의 인덱스 값을 a,b라 하면
# 시작점이 흰색인 경우는 a+b를 2로 나눈 나머지가 0인 부분이 흰색이 되고 나머지가 1인 부분이 검은색으로 칠해져야 하며 검은색인 경우는 반대가 된다.
# 내가 했던 방식과 비슷하게 2가지 색칠법에 대해 최소값 변수를 2개로 두어 유지하고 8x8 영역을 탐색한 경우 그 최소값 끼리 비교하고 이때까지 
# 설정한 영역에 대해 탐색한 최소값가 비교하여 다시 최소값을 출력한다. 