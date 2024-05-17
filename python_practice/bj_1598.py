a,b = map(int, input().split(" "))

#각 세로줄은 몫이 i-1이고 나머지가 1인 수부터 1씩 증가하여 몫이 i고 나머지가 0인 수로 끝난다.
# a = 4*k1 + a1
# b = 4*k2 + b1라고 하면
# 직각 거리 = m이라 하면
# m => a + 4*k' + n' = b (a < b일때, -2 <= n <= 3) = 4 * k2 + b1 = 4 (k1 + k') +a1 + n'
# m = k' + |n'| 
# k' => 가로길이 a,b중 하나만 4의 배수라면 몫 차이의 +1, 아니면 몫 차이
# n' => 나머지 배열 [1,2,3,0] 이므로 a,b가 4의 배수일때 세로 길이를 계산할땐 나머지를 0으로 취급한다, 다른 경우엔 나머지끼리 빼고 절댓값을 취하면 된다.
k = 0
temp = a
a = b if b > a else a
b = temp if b > temp else b
if(a%4 == 0 and b%4 != 0):
    k = (a//4-1)-b//4
elif(a%4 != 0 and b%4 == 0):
    k = a//4 - (b//4-1)
else:
    k = a//4 - b//4


n1 = 4 if a%4==0 else a%4
n2 = 4 if b%4 == 0 else b%4
n = abs(n1-n2)
print(k+n)
