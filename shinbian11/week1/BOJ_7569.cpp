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

int n, m, h, day;
int dx[6] = { 0,0,1,-1,0,0 }; // 동서남북, 상하
int dy[6] = { 1,-1,0,0,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
int arr[101][101][101];
int one, minusOne;

bool allRipen() {
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// 안 익은 토마토가 하나라도 있으면 false 반환
				if (arr[i][j][k] == 0) return false;
			}
		}
	}

	// 다 익었으면 true 반환
	return true;
}

int main()
{
	F_I;

	
	cin >> m >> n >> h;

	queue<tuple<int, int, int> >q;

	for (int k = 0; k < h; k++){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push({ i,j,k });
					one++;
				}
				else if (arr[i][j][k] == -1) {
					minusOne++;
				}
			}
		}
	}
	
	if (one + minusOne == h * m * n) { // 이미 존재하는 모든 토마토가 익었다.
		cout << 0 << '\n';
		return 0;
	}
	
	
	if (q.size() == 0) { // 현재 큐에 들어간 데이터가 없다(큐의 사이즈가 0)?? ==> 익지 않은 토마토를 익힐 토마토가 없다!! ==> 그렇다고 모든 토마토가 다 익은 것도 아니다 (바로 윗 코드에서 걸러낸 조건!)
		cout << -1 << '\n';
		return 0;
	}

	while (true) {
		int qSize = q.size();
		for (int s = 0; s < qSize; s++) {
			int sx, sy, sh;
			tie(sx, sy, sh) = q.front();
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = sx + dx[i];
				int ny = sy + dy[i];
				int nh = sh + dh[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && nh >= 0 && nh < h) {
					if (arr[nx][ny][nh] == 0) {
						arr[nx][ny][nh] = 1;
						q.push({ nx,ny,nh });
					}
				}
			}
		}

		// 일단 익힐 수 있는 토마토를 모두 익혔고, 전체가 모두 익었다면 날짜 수 출력
		if (q.size() == 0 && allRipen()) {
			cout << day << '\n';
			return 0;
		}
		else if (q.size() == 0 && !allRipen()) { // 일단 익힐 수 있는 토마토를 모두 익혔는데, 그럼에도 불구하고 안 익은 토마토가 존재한다면 -1 출력 (아직 안 익은 토마토는 영원히 익힐 수 없다.)
			cout << -1 << '\n';
			return 0;
		}
		day++;
	}

	return 0;
}
