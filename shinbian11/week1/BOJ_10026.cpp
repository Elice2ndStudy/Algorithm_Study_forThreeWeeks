#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } // 최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } // 최소공배수

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n;


int BFS(vector<string> v, vector< vector<bool> > visited, bool hasColorWeekness) {

	queue<pi> q;
	int cnt = 0;
	int flag = 0, nextFlag = 0;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (!visited[x][y]) {
				q.push({ x,y });
				while (!q.empty()) {

					int x, y;
					tie(x, y) = q.front();
					q.pop();

					if (hasColorWeekness) {
						flag = 0;
						nextFlag = 0;

						if (v[x][y] == 'R' || v[x][y] == 'G') flag = 1;
						else if (v[x][y] == 'B') flag = 2;
					}

					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
							if (!visited[nx][ny]) {

								if (hasColorWeekness) {

									if (v[nx][ny] == 'R' || v[nx][ny] == 'G') nextFlag = 1;
									else if (v[nx][ny] == 'B') nextFlag = 2;

									if (flag == nextFlag) {
										visited[nx][ny] = true;
										q.push({ nx,ny });
									}
								}
								else {
									if (v[x][y] == v[nx][ny]) {
										visited[nx][ny] = true;
										q.push({ nx,ny });
									}
								}

							}
						}
					}
				}
				cnt++;
			}
		}
	}


	return cnt;
}

int main()
{
	F_I;

	cin >> n;

	vector<string> v(n);
	vector< vector<bool> > visited(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) cin >> v[i];

	cout << BFS(v, visited, false) << ' ' << BFS(v, visited, true) << '\n';

	return 0;
}
