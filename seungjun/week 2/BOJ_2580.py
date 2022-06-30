# 스도쿠
# https://www.acmicpc.net/problem/2580

import sys

sudoku = []
empty = []

for _ in range(9):
    sudoku.append(list(map(int, input().split(" "))))

#모든 빈 칸을 파악해준다.
for i in range(9):
    for j in range(9):
        if sudoku[i][j] == 0:
            empty.append((i,j))

def checkRow(x, num):
    for i in range(9):
        if num == sudoku[x][i]:
            return False
    return True
def checkCol(y, num):
    for i in range(9):
        if num == sudoku[i][y]:
            return False
    return True
def checkBox(x, y, num):
    nx = x // 3 * 3
    ny = y // 3 * 3
    for i in range(3):
        for j in range(3):
            if num == sudoku[nx+i][ny+j]:
                return False
    return True

def dfs(idx):
    # 빈칸을 모두 채웠다면 답을 찾은 것이므로 출력
    if idx == len(empty):
        for i in range(9):
            print(*sudoku[i])
        sys.exit()

    #여기를 돌고 있다는 것은 빈칸이 남아있다는 것
    for number in range(1, 10):
        # number 는 1~9 중 하나의 수.
        # 빈 칸에 number를 넣을 시 스도쿠 3가지 규칙이 통과하는지 확인해주자
        x = empty[idx][0]
        y = empty[idx][1]
        
        if checkRow(x, number) and checkCol(y, number) and checkBox(x, y, number):
            sudoku[x][y] = number
            dfs(idx+1)
            sudoku[x][y] = 0
dfs(0)