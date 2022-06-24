import sys
input = sys.stdin.readline
def egg(x):

    if x == N:
        count = 0
        for i in range(N):
            if myInput[i][0] <= 0:
                count += 1
        return count

    if myInput[x][0] <= 0:
        return egg(x+1)

    brokenEgg = 0
    for i in range(N):
        if myInput[i][0] < 0 or i == x : continue

        myInput[i][0] -= myInput[x][1]
        myInput[x][0] -= myInput[i][1]

        brokenEgg = max(brokenEgg, egg(x+1))

        myInput[i][0] += myInput[x][1]
        myInput[x][0] += myInput[i][1]

    return brokenEgg
     
N = int(input())
myInput = [list(map(int, input().split())) for _ in range(N)]
print(egg(0))