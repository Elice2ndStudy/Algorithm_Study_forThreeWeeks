# 보물섬
# https://www.acmicpc.net/problem/2589
from collections import deque
from inspect import trace

n, m=map(int, input().split())
treasure = []
for i in range(n):
  treasure.append(list(input()))

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def bfs(i, j):
  queue = deque()
  queue.append((i,j))
  visited=[[0]*m for _ in range(n)]
  visited[i][j]=1
  count = 0
  while queue:
    x, y = queue.popleft()
    for i in range(4):
      nx=x + dx[i]
      ny=y + dy[i]
      if nx<0 or nx>=n or ny<0 or ny>=m:
        continue
      elif treasure[nx][ny]=='L' and visited[nx][ny]==0:
        visited[nx][ny]=visited[x][y]+1
        count = max(count,visited[nx][ny])
        queue.append((nx,ny))
  return count-1

result=0
for i in range(n):
  for j in range(m):
    if treasure[i][j]=='L':
      result=max(result,bfs(i,j))

print(result)