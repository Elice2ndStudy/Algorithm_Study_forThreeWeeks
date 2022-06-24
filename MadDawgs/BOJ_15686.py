import sys
from collections import deque
from itertools import combinations
input = sys.stdin.readline

def selectStore():
    for i in range(N):
        for j in range(N):
            if myInput[i][j] == 2:
                storeList.append([i, j])
    
    return list(combinations(storeList, M))

def getDistance(x, y, storeList):
    distance = N*N
    for i in range(M):
            distance = min(distance, abs(x - storeList[i][0]) + abs(y - storeList[i][1]))
    return distance

def chickenDistance():
    total_distance = 100000
    store = selectStore()   

    for stores in store:        
        arr = []
        for i in range(M):
            myInput[stores[i][0]][stores[i][1]] = -1
        
        for x in range(N):
            for y in range(N):
                
                if myInput[x][y] == 1:
                    arr.append(getDistance(x, y, stores))

        for i in range(M):
            myInput[stores[i][0]][stores[i][1]] = 2

        total_distance = min(sum(arr), total_distance)
    return total_distance
                

storeList = []
N, M = map(int, input().split())
myInput = [list(map(int, input().split())) for _ in range(N)]
print(chickenDistance())