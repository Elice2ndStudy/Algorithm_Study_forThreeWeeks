# [BOJ] 1463 / 1로 만들기 / 실버3 / 파이썬
import math

n = int(input())
# 쓰레기값,1,2,3,4번째 케이스를 dp 리스트에 넣어줬음 => index를 맞추기 위해서
dp = [0,0,1,1,2]
for i in range(5,n+1):
    # 조건 1 , 조건 2 , 조건 3 => 최소값을 구하기 위해서 무한대값으로 지정했음
    one , two , three = math.inf , math.inf , dp[i-1]
    if i % 3 == 0:
        one = dp[i//3]
    if i % 2 == 0:
        two = dp[i//2]
    # 조건 1,2,3를 한번 거치고나서 최소값을 구하는 거니까 1을 앞에서 더해줬다.
    dp.append(1 + min(one , two , three))
print(dp[n])
