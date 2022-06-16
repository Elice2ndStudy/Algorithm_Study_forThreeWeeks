# 점프 게임.
# https://www.acmicpc.net/problem/15558

from collections import deque

n, k = map(int, input().split())
arr = [list(map(int, input())) for _ in range(2)]
visited = [[False] * n] * 2
lava = 0
def bfs(point):
    global lava
    q = deque([point])
    while q:
        for _ in range(len(q)):
            x, idx = q.popleft()
            if idx + 1 >= n or idx + k >= n:
                return True
            #한칸 앞으로
            if arr[x][idx+1] and not visited[x][idx+1]:
                q.append((x, idx+1))
                visited[x][idx+1] = True
                print(lava)
            #한칸 뒤로
            if idx-1 > lava +2 and arr[x][idx-1] and not visited[x][idx-1]:
                q.append((x, idx-1))
                visited[x][idx-1] = True
                print(lava)
            #반대편 k칸 앞으로
            if arr[(x+1)%2][idx+k] and not visited[(x+1)%2][idx+k]:
                q.append(((x+1)%2, idx+k))
                visited[(x+1)%2][idx+k] = True
                print(lava)
        lava += 1

print(1 if bfs([0,0]) else 0)