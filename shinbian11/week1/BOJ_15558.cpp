#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } // 최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } // 최소공배수



int main()
{
	F_I;

	int n, k;
	cin >> n >> k;

	int dx[4] = { 0,0,1 };
	int dy[4] = { 1,-1, k };

	vector<string> v(2);
	vector< vector<bool> > visited(2, vector<bool>(n, false));
	for (int i = 0; i < 2; i++) {
		string str;
		cin >> str;
		v[i] = str;
	}

	queue< pair<pi, int> > q;
	q.push({ { 0,0 }, 0 });

	while (!q.empty()) {

		int x, y, time;
		tie(x,y) = q.front().first;
		time = q.front().second;
		q.pop();

		if (time >= n) continue;
		
		for (int i = 0; i < 3; i++) {
			
			int nx = (x + dx[i]) % 2;
			int ny = y + dy[i];

			if (ny >= n) { // 다음에 이동할 칸이 N번 칸보다 더 큰 칸으로 이동하는 경우 => 게임 클리어!
				cout << 1 << '\n';
				return 0;
			}

			// time 변수 : 1초에 한 칸씩 각 줄의 첫 칸이 사라지므로, 사라진 칸으로는 다음에 이동할 수 없다는 의미로, ny의 범위를 ny > time && ny < n 으로 하기!
			if (ny > time && ny < n) {

				if (v[nx][ny] == '0') continue; // 위험한 칸은 이동 불가
				if (visited[nx][ny]) continue; // 이미 한번 이동한 칸은 불가

				q.push({ { nx,ny }, time + 1 });
				visited[nx][ny] = true; // 방문 표시를 큐에서 뺀 다음이 아니라, 큐에 넣을 때 해야 중복 방문이 일어나지 않는다. (출처 : https://www.acmicpc.net/board/view/33189 )
			}
		}
	}

	cout << 0 << '\n';

	return 0;
}
