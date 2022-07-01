# [BOJ] 15565 / 귀여운 라이언 / 실버1 / 파이썬
import math

n , k = map(int,input().split())
n_list = list(map(int,input().split()))
idx_list = []

minValue = math.inf

for idx, i in enumerate(n_list, 1):
    if i == 1:
        idx_list.append(idx)

for i in range(0, len(idx_list)-k+1):
    temp = idx_list[i+k-1] - idx_list[i]
    minValue = min(minValue , temp)

if minValue == math.inf:
    print(-1)
else:
    print(minValue + 1)