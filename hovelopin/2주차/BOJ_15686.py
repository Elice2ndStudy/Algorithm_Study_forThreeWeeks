# [BOJ] 15686 / 치킨 배달 / 골드5 / 파이썬
import math
import sys
from itertools import combinations

n , m = map(int,input().split())
city = [list(map(int,input().split())) for _ in range(n)]
res = math.inf
house = []
chicken = []

for i in range(n):
    for j in range(n):
        # 집이면 집에 치킨집이면 치킨집에 값을 넣는다.
        if city[i][j] == 1:
            house.append([i,j])
        elif city[i][j] == 2:
            chicken.append([i,j])
print(house)
print(chicken)

# 치킨집중에 m개를 골랐을때 도시의 치킨거리가 가장 작게 될 경우
for c in combinations(chicken , m):
    print(c)
    temp = 0
    for h in house:
        dis = math.inf
        for j in range(m):
            dis = min(dis , abs(h[0] - c[j][0]) + abs(h[1] - c[j][1]))
        temp += dis
    res = min(res , temp)

print(res)




