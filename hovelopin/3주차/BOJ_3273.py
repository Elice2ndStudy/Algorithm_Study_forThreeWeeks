# [BOJ] 3273 / 두 수의 합 / 실버3 / 파이썬
import sys

n = int(input())
n_list = sorted(list(map(int,sys.stdin.readline().split())))
x = int(input())

cnt = 0
start , end = 0 , n - 1

while start < end:
    temp = n_list[start] + n_list[end]
    # temp가 x랑 같으면 올리고 start를 올린다.
    if temp == x:
        cnt += 1
        start += 1
    # temp가 x보다 작다는 것은 값이 더 커야한다는거라서 start를 올린다.
    elif temp < x:
        start += 1
    else:
        end -= 1

print(cnt)