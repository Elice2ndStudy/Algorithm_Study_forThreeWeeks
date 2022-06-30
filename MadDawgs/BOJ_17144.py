import sys
input = sys.stdin.readline


def dust():
    temp = [[0] * C for _ in range(R)]
    di = [(-1,0), (1, 0), (0, 1), (0, -1)]
    for x in range(R):
        for y in range(C):
            if myInput[x][y] != -1:
                amount = myInput[x][y]//5
                last = myInput[x][y]
                for d in di:
                    nx = x + d[0]
                    ny = y + d[0]
                    if 0 <= nx < R and 0 <= ny < C:
                        if myInput[nx][ny] != -1:
                            temp[nx][ny] += amount
                            last -= amount
                    print(temp)
                temp[x][y] += last
    temp[location[0]][0] = -1
    temp[location[1]][0] = -1
    return temp


def airFresher(arr):
    print(arr)

    up = location[0]
    down = location[1]
    for i in range(up-1, 0, -1):
        arr[i][0] = arr[i-1][0]
    arr[0][0] = 0

    for i in range(down+2, R):
        arr[i-1][0] = arr[i][0]
    arr[R-1][0] = 0


    for i in range(0, C-1):
        arr[0][i] = arr[0][i+1]
        arr[R-1][i] = arr[R-1][i+1]
    arr[0][C-1] = 0
    arr[R-1][C-1] = 0

  
    for i in range(0, up):
        arr[i][C-1] = arr[i+1][C-1]
    arr[up][C-1] = 0

 
    for i in range(R-1, down, -1):
        arr[i][C-1] = arr[i-1][C-1]
    arr[down][C-1] =0


    for i in range(C-1, 1, -1):
        arr[up][i] = arr[up][i-1]
        arr[down][i] = arr[down][i-1]

    arr[up][1] = 0
    arr[down][1] = 0

def solution():
    answer = 0
    for i in range(T):
        dustMap = dust()
        airFresher(dustMap)
    for i in range(R):
        for j in range(C):
            if dustMap[i][j] != -1:
                answer += dustMap[i][j]
    return answer  


          


R, C, T = map(int, input().split())
myInput = [list(map(int, input().split())) for _ in range(R)]
location = []
for i in range(R):
    if myInput[i][0] == -1:
        location.append(i)
print(solution())

