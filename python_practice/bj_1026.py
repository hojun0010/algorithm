
n = int(input())
arr_A = list(map(int, input().split(" ")))
arr_B = list(map(int, input().split(" ")))

#A[i]xB[i] 원소들의 합이 최소가 되도록 A를 재배열, 그 합을 출력한다. B는 변경하지 않음으로 결국 B의 작은 수에는 큰 값을 배치, 큰 값에는 작은 값을 배치하면 된다
# 결국 B를 오름차순 정렬 시킨다면 A를 내림차순으로 정렬시켰을때의 각원소 곱의 합이 최소값이 된다.
arr_A.sort()
arr_B.sort(reverse=True)

# print(arr_A)
# print(arr_B)
sum = 0
for i in range(0,n):
    sum += arr_A[i]*arr_B[i]

print(sum)
