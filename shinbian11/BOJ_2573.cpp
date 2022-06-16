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

int arr[304][304];
bool d[304][304];
bool v[304][304]; // 해당 턴에 빙산인 아이들의 기록을 남기는 배열
bool visited[304][304] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, m, year;
queue<pi> q;

void checkIceberg() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0) {
				v[i][j] = true;
			}
		}
	}
}

void resetIcebergCheck() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v[i][j] = false;
		}
	}
}

// BFS 이용하여 빙산의 덩어리 개수를 셈 
bool IcebergGroupCnt() { 
	int group = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			d[i][j] = false;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0 && !d[i][j]) {
				d[i][j] = true;
				queue<pi> tq;

				tq.push({ i,j });
				while (!tq.empty()) {
					int x, y;
					tie(x, y) = tq.front();
					tq.pop();
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
							if (arr[nx][ny] > 0 && !d[nx][ny]) {

								d[nx][ny] = true;
								tq.push({ nx,ny });
							}
						}
					}
				}
				group++;
			}
		}
	}
	
	return group >= 2;
}

int main()
{
	F_I;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0) {
				q.push({ i,j });
			}
		}
	}


	while (true) {
		checkIceberg(); // 빙산이 남아있는 곳을 체크
		if (IcebergGroupCnt()) { // 빙산이 2덩어리 이상이라면 true 반환
			cout << year << '\n';
			return 0;
		}

		int qSize = q.size();

		// 이번 year에 높이가 0보다 큰 빙산들을 반복문을 통해 하나씩 반복하기
		for (int i = 0; i < qSize; i++) {
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			
			int melt = 0;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					// 빙산 주변에 바닷물(높이가 0 + 이번 턴에 빙산이었는데, 주변 바닷물에 의해 녹아버린 빙산이 아니어야 함)
					if (arr[nx][ny] == 0 && !v[nx][ny]) {
						melt++;
					}
				}
			}
			
			// 바닷물 개수만큼 빙산을 녹이기

			if (arr[x][y] - melt <= 0) {
				arr[x][y] = 0;
			}
			else {
				arr[x][y] -= melt; 
				q.push({ x,y }); // 아직 빙산의 높이가 남아있다면, 큐에 push 하기
			}
		}

		year++; // 1년 증가

		
		if (q.size() == 0 && IcebergGroupCnt()) { // 더 이상 남아있는 빙산이 없을 때, 빙산의 덩어리가 2개 이상이라면, 년도 출력
			cout << year << '\n';
			break;
		}
		else if (q.size() == 0 && !IcebergGroupCnt()) { // 더 이상 남아있는 빙산이 없을 때, 빙산의 덩어리가 2개보다 적다면, 빙산이 다 녹을 때까지 빙산이 분리되지 않는다는 의미니까 0을 출력
			cout << 0 << '\n';
			break;
		}
		resetIcebergCheck(); // 빙산이 남아있는 곳을 체크한 흔적을 모두 지우기
	}

	return 0;
}
