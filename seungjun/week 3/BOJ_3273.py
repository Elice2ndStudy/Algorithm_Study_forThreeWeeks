# 두 수의 합
# https://www.acmicpc.net/problem/3273

n = int(input())
arr = list(map(int, input().split()))
x = int(input())

start, end = 0, n-1
ans = 0

arr.sort()
while start < end:
    sum = arr[start]+arr[end]
    if sum == x:
        ans += 1
    if sum < x:
        start += 1
        continue
    end -= 1

print(ans)