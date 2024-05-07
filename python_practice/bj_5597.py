array = list(map(int,range(31))) #0~29=길이 30인 리스트 생성
#array = list(map(int,range(30))) 으로 할경우 입력당시 
#1번 학생에 해당하는 array[0]의 초기값이 0으로 설정되 1번학생은 무조건 숙제를 내는것으로 간주된다
for i in range(0,28): #28번 반복
    k = int(input())
    array[k] = 0 

array.sort()
cnt = 0
for i in range(0,len(array)):
    if(array[i] != 0):
        print(array[i],end="")
        cnt += 1
    else:
        continue
    if(cnt == 2):
        break
    print()
