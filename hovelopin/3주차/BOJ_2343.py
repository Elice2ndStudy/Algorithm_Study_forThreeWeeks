# [BOJ] 2343 / 기타 레슨 / 실버1 / 파이썬
n , m = map(int,input().split())
lesson = list(map(int,input().split()))

# 시작과 끝점 => 블루레이를 가장 많이 쓰려면 최대값을 담을 수 있어야 하고 하나에 담으려면 총합을 다 담을 수 있어야 한다.
# 테스트 케이스에서는 9와 45가 된다.
start , end = max(lesson) , sum(lesson)

while start <= end:
    mid = (start + end) // 2
    # 최소 1개 이상을 담아야 하기 때문에 cnt를 1로 시작한다.
    cnt = 1
    temp = 0

    # 레슨을 돌면서 합계를 구해준다.
    for i in range(len(lesson)):
        if temp + lesson[i] > mid:
            cnt += 1
            temp = 0
        temp += lesson[i]

    # cnt가 크면 mid를 줄이고 작으면 mid를 올린다
    if cnt <= m:
        end = mid - 1
    else:
        start = mid + 1

print(start)




