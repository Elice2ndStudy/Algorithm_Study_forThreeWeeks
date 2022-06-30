# 호텔.
# https://www.acmicpc.net/problem/1106
import sys
input = sys.stdin.readline

c, n = map(int, input().split())
arr = []
dp = [0] + [int(1e9)] * (c+100) 
for _ in range(n):
    arr.append(list(map(int, input().split())))
    # [cost, customer]

arr_sort = sorted(arr, key = lambda x: x[0])
# x[0]인 cost를 기준으로 오름차순 정리를 해준다
# 그냥 sorted을 해주어도 되지만 lambda sorting이 더 범용적이라 채택

for cost, customer in arr_sort:
    for i in range(customer, c+100):
        dp[i] = min(dp[i], dp[i-customer] + cost)


print(min(dp[c:]))
print(dp)