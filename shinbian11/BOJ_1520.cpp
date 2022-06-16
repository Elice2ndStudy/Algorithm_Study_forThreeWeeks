#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int n, m;
int arr[504][504];
int dp[504][504];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int solution(int x, int y) {

	if (x == n - 1 && y == m - 1) return 1; // 도착점 -> 도착점의 경로의 개수는 1가지이다.
	if (dp[x][y] != -1) return dp[x][y]; // memoization

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (arr[x][y] > arr[nx][ny]) { // 높이가 더 낮은 곳으로만 이동할 수 있다.
				dp[x][y] += solution(nx, ny); // "이번에 이동할 곳 (nx, ny) => 도착점 (n-1, m-1) 로의 경로의 개수" 들을 모두 더하기
			}
		}
		
	}

	return dp[x][y];
}

int main()
{
	F_I;

	// DP + DFS 개념 사용!

	// dp[a][b] : (a, b) 에서 도착점, 즉 (n-1, m-1)로의 경로의 개수

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	fill(&dp[0][0], &dp[503][504], -1);


	cout << solution(0, 0) << '\n';	

	return 0;
}