#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } // 최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } // 최소공배수


int dirt[54][54];
int d[54][54];

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };
int copyDirt[54][54];

int n, m, t;
int ux = -1, uy = -1, dx = -1, dy = -1; //공기청정기의 위치

void diffusion() // 미세먼지 확산
{

    // dirt 배열을 copyDirt에 복사하는 이유? 확산은 미세먼지가 있는 모든 칸에서 동시에 일어나야 하므로, 바로 이전 (x, y-1)에 있는 칸이 방금 전에 상태가 변경되었다 하더라도, 그것이 지금 칸(x, y)에서 영향을 받으면 안됨!
    memset(copyDirt, 0, sizeof(copyDirt));

    for (int x = 0; x < n; x++)
    {
        for (int y = 0;y < m; y++)
            copyDirt[x][y] = dirt[x][y];
    }

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (x == ux && y== uy) continue; // 공기청정기가 있는 위치는 미세먼지 확산 X
            if (x == dx && y == dy) continue; // 공기청정기가 있는 위치는 미세먼지 확산 X

            if (!copyDirt[x][y]) continue; // 미세먼지가 없는 위치에서는 확산 X

            int spread = copyDirt[x][y] / 5;
            int cnt = 0; // (x,y)에서 미세먼지를 확산할 수 있는 구역의 개수

            for (int k = 0; k < 4; k++)
            {
                int nx = x + mx[k];
                int ny = y + my[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                // 이동할 곳이 공기청정기가 있는 위치라면 미세먼지 확산 X
                if (nx == ux && ny == uy) continue;
                if (nx == dx && ny == dy) continue;

                dirt[nx][ny] += spread;
                cnt += 1;
            }

            dirt[x][y] -= spread * cnt;
        }
    }


}

void AirCleaner() // 공기청정기 가동
{

    // 공기 청정기 위쪽 부분 (반시계방향)
    for (int i = ux - 2; i >= 0; i--)
        dirt[i + 1][0] = dirt[i][0];
    for (int j = 1; j <= uy + m - 1; j++)
        dirt[0][j - 1] = dirt[0][j];
    for (int i = 1; i <= ux; i++)
        dirt[i - 1][uy + m - 1] = dirt[i][uy + m - 1];
    for (int j = uy + m - 2; j >= 1; j--)
        dirt[ux][j + 1] = dirt[ux][j];
    dirt[ux][1] = 0; //공기청정기에서 방금 나온 칸은 0이다. (깨끗한 공기)


    // 공기 청정기 아래쪽 부분 (시계방향)
    for (int i = dx + 2; i <= n - 1; i++)
        dirt[i - 1][0] = dirt[i][0];
    for (int j = 1; j <= m - 1; j++)
        dirt[n - 1][j - 1] = dirt[n - 1][j];
    for (int i = n - 2; i >= dx; i--)
        dirt[i + 1][m - 1] = dirt[i][m - 1];
    for (int j = dy + m - 2; j >= 1; j--)
        dirt[dx][j + 1] = dirt[dx][j];
    dirt[dx][1] = 0; // 공기청정기에서 방금 나온 칸은 0이다. (깨끗한 공기)
}

int SumOfDirt() // t번 반복 이후에 남아있는 모든 미세먼지 양 합산
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            sum += dirt[i][j];
    }

    return sum; // 공기청정기가 있는 위치는 -1에서 0으로 값을 바꿨으므로 (입력받는 과정에서) , 여기에서 추가적인 처리를 해줄 필요는 없다.
}

int main()
{
    F_I;

    //[백준] 17144번 : 미세먼지 안녕! (BFS)

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> dirt[i][j];

            if (dirt[i][j] == -1) //공기청정기의 위치 정보는 기록만 해두고, 그 이후에서는 공기청정기도 그냥 0으로 취급!
            {
                if (ux == -1)
                {
                    ux = i;
                    uy = j;
                }
                else
                {
                    dx = i;
                    dy = j;
                }
                dirt[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= t; i++) // 확산과 공기청정기 가동을 t번 반복!
    {
        diffusion(); // 미세먼지 확산
        AirCleaner(); // 공기청정기 가동
    }

    cout << SumOfDirt() << '\n'; // t번 반복 이후에 남아있는 모든 미세먼지 양 합산

    return 0;
}