# 오르막 수.
# https://www.acmicpc.net/problem/11057

n = int(input())

dp = [1] * 11
dp[0] = 0
for a in range(n):
    for i in range(1, 11):
        dp[i] = (dp[i] + dp[i-1])%10007
    # print(dp)

print(dp[-1]%10007)

