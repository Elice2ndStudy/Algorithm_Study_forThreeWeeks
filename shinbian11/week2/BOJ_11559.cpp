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
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

vector< vector<char> > matrix(6, vector<char>(12));
vector< vector<bool> > visited(6, vector<bool>(12, false));

int chain;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


bool BFS(int x, int y) {


	queue<pi> test;
	queue<pi> q;

	int qCnt = 0;

	test.push({ x,y });
	q.push({ x,y });

	visited[x][y] = true;

	while (!q.empty()) {

		int x, y;
		tie(x, y) = q.front();
		q.pop();

		qCnt += 1;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= 6 || ny < 0 || ny >= 12) continue;
			if (matrix[nx][ny] == '.') continue;
			if (visited[nx][ny]) continue;
			if (matrix[nx][ny] != matrix[x][y]) continue;

			test.push({ nx,ny });
			q.push({ nx,ny });
			visited[nx][ny] = true;
		}
	}

	// 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 qCnt 가 4 이상일 것이다.
	if (qCnt >= 4) {
		// 연결된 같은 색 뿌요들이 한꺼번에 없어진다 (그 정보는 이제 test 큐에 저장되어 있다.)
		while (!test.empty()) {
			int x, y;
			tie(x,y) = test.front();
			test.pop();
			matrix[x][y] = '.';
		}

		return true; // 이번 턴에서 연쇄가 일어난 부분이 최소 1번은 있었다는 의미!
	}

	return false;
}


int main() {

	F_I;

	for (int i = 0; i < 12; i++) {

		string str;
		cin >> str;

		for (int j = 0; j < 6; j++) {
			matrix[j][i] = str[j];
		}
	}

	while (true) {

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 12; j++) visited[i][j] = false;
		}

		// 터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고, 여러 그룹이 터지더라도 한번의 연쇄만 추가되어야 한다.
		// canChainIncrease이 true가 된다면, 이번 턴에서 한번의 연쇄가 추가된다는 의미이다.
		bool canChainIncrease = false;


		// STEP 1 : 연쇄 여부 체크 => 연쇄된 공간은 모두 . 표 처리, 연쇄 횟수는 1 증가시키면 됨
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 12; j++) {
				
				// resetVisited();

				if (matrix[i][j] != '.' && !visited[i][j]) {
					if (BFS(i, j)) canChainIncrease = true;
				}
			}
		}

		// 연쇄 횟수 1 증가
		if (canChainIncrease) chain += 1;
		else break;

		// STEP 2 : 중력에 의해 터진 공간으로 떨어져야 하는 경우가 발생한다면 최대로 떨어뜨리기
		for (int i = 0; i < 6; i++) {
			queue<char> q;
			for (int j = 11; j >= 0; j--) if (matrix[i][j] != '.') q.push(matrix[i][j]);
			for (int j = 11; j >= 0; j--) {
				if (q.empty()) {
					matrix[i][j] = '.';
					continue;
				}
				matrix[i][j] = q.front();
				q.pop();
			}
		}
	}

	cout << chain << '\n';

	return 0;
}