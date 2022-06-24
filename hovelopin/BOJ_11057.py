# [BOJ] 11057 / 오르막 수 / 실버1 / 파이썬
n = int(input())
# n=1일때 0~9까지는 모두 다 1이다.
dp = [1] * 10

# 만일 3자리수라고 하면 100 ~ 999
for i in range(n-1):
    for j in range(1,10):
        dp[j] += dp[j-1]

print(sum(dp)%10007)
