import sys
input = sys.stdin.readline

def z(n, r, c):
    # 종료조건
    if n == 1:
        return basis[r][c]
    # 4 구영으로 나눠서 진행 
    if r >= 2**(n-1) and c >= 2**(n-1):
        nr = r - 2**(n-1)
        nc = c - 2**(n-1)
        return (2**(2*n-2))*3 + z(n-1, nr, nc)

    if r >= 2**(n-1) and c < 2**(n-1):
        nr = r - 2**(n-1)
        nc = c
        return (2**(2*n-2))*2 + z(n-1, nr, nc)

    if r < 2**(n-1) and c >= 2**(n-1):
        nr = r
        nc = c - 2**(n-1)
        return (2**(2*n-2)) + z(n-1, nr, nc)

    if r < 2**(n-1) and c < 2**(n-1):
        nr = r
        nc = c
        return z(n-1, nr, nc)
    

N, r, c = map(int, input().split())
basis = [[0, 1], [2, 3]]
print(z(N, r, c))