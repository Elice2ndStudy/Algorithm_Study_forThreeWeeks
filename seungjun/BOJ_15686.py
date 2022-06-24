# 치킨 배달
# https://www.acmicpc.net/problem/15686
from itertools import combinations
n, m = map(int, input().split())

city = []
houses = []
chickens = []
result = 1e9
for _ in range(n):
    city.append(list(map(int, input().split())))

# 마을 내 집(house)과 치킨집(chicken)을 분류
for r in range(n):
    for c in range(n):
        if city[r][c] == 1:
            houses.append([r,c])
        if city[r][c] == 2:
            chickens.append([r,c])

# m개의 치킨집을 선택하는 경우의 수를 combo라고 하자
for combo in combinations(chickens, m):
    total = 0           # total == 도시 치킨집 거리
    for house in houses:
        distance = 999
        #각 집마다 치킨집까지의 거리
        for chicken in combo:
            distance = min(distance, abs(house[0]-chicken[0]) + abs(house[1]-chicken[1]))
        total += distance

    # 여태까지 나왔던 조합 중 가장 낮았던 거리로 계속 갱신해준다
    result= min(result, total)

print(result)