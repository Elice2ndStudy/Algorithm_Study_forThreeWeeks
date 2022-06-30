import sys
input = sys.stdin.readline

def findRyan():
    # K개가 들어있는 첫번째 배열의 start와 end 찾기
    count = 0
    for i in range(N):
        if myInput[i] == 1:
            j = i
            while count < K and j < N:
                if myInput[j] == 1:
                    count += 1
                j += 1
            if j != N:
                start = i
                end = j
                break
            else: return -1
        if i == N - 1:
            return -1
    answer = end - start
    
    #다음 start와 end 찾기
    while end < N :
        if myInput[end] == 1:
            start += 1
            while myInput[start] == 2:
                start += 1
            answer = min(answer, end - start + 1)
        end += 1               
    return answer

N, K = map(int, input().split())
myInput = list(map(int, input().split()))
print(findRyan())
