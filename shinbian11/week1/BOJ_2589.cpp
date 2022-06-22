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

int n, m, ans;
char arr[54][54];
bool visited[54][54];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int BFS(int x, int y) {
	int step;
	queue< tuple<int,int,int> > q;
	q.push({ x,y,0 });
	visited[x][y] = true;

	while (!q.empty()) {

		int x, y;
		tie(x, y, step) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (arr[nx][ny] == 'L' && visited[nx][ny] == false) {
					q.push({ nx,ny,step + 1 });
					visited[nx][ny] = true;
				}

			}
		}
	}

	return step;

}

int main()
{
	F_I;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
		}
	}
	
	fill(&visited[0][0], &visited[53][54], false);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 육지가 있는 모든 곳에서 BFS를 통해 갈 수 있는 가장 먼 거리값을 구하고, 그들 중 최댓값이 정답이다.
			if (arr[i][j] == 'L') {
				fill(&visited[0][0], &visited[53][54], false); // false 로 초기화
				int tmp = BFS(i, j);
				if (tmp > ans) ans = tmp;
			}
		}
	}

	
	cout << ans << '\n';

	return 0;
}