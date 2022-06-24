# [BOJ] 2579 / 계단 오르기 / 실버3 / 파이썬
n = int(input())
steps = [0] + [int(input()) for _ in range(n)]
dp = [0] * (n+1)

if n == 1:
    print(steps[1])
else:
    dp[1] = steps[1]
    dp[2] = steps[1] + steps[2]
    # 우리가 따져봐야 하는 부분은 3번 연속으로 올라오는것이 아닌 최대 2번 연속이고 마지막 계단은 밟는다.
    # 따라서 마지막 계단은 무조건 올라가야한다는 의미에서 n-1 , n 인 경우와 n-2 , n인 경우가 있을 수 있다.
    # 따라서 n-1 , n인 경우에는 n-2를 거르고 dp[n-3]까지의 최대 값에서 마지막 2개를 더하고
    # n-2 , n인 경우에는 dp[n-2]의 최대를 구하고 마지막 n만 더해준다. 그 2개의 경우중에 최대값을 구하기
    for i in range(3 , n+1):
        dp[i] = max(dp[i-3]+steps[i-1]+steps[i] , dp[i-2]+steps[i])
print(dp[n])