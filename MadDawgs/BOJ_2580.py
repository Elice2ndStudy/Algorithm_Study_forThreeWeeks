import sys
input = sys.stdin.readline

def rowLineCheck(x, num):
    for y in range(9):
        if num == myInput[x][y]:
            return 0
    return 1

def colLineCheck(y, num):
    for x in range (9):
        if num == myInput[x][y]:
            return 0
    return 1

def boxCheck(x, y, num):
    nx = x // 3
    ny = y // 3
    for i in range(nx*3, nx*3+3):
        for j in range(ny*3, ny*3+3):
            if num == myInput[i][j]:
                return 0
    return 1


def promising(x, y, num):
    if rowLineCheck(x, num) and colLineCheck(y, num) and boxCheck(x, y, num):
        return 1
    return 0


def sdocu(depth):
    if depth == numberOfZero:
        for line in myInput:
            print(" ".join([str(_) for _ in line]))
        exit(0)
    
    x = location[depth][0]
    y = location[depth][1]

    for i in range(1, 10):
        if promising(x, y, i):
            myInput[x][y] = i
            sdocu(depth+1)
            myInput[x][y] = 0


myInput = [list(map(int, input().split())) for _ in range(9)]
numberOfZero = 0
location = []
for i in range(9):
    for j in range(9):
        if myInput[i][j] == 0:
            numberOfZero += 1
            location.append((i, j))

sdocu(0)