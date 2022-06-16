#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> p;
typedef pair<p, int> pp;
queue<pair<p, p>>q;
pp dir[6] = { { {-1,0}, 0 },{ {1,0},0 },{ {0,-1},0 },{{ 0,1},0 },{{0,0},1},{{0,0},-1} };
int m, n, h, cnt, ans;
int arr[101][101][101],visit[101][101][101];
int tomato()
{
	if (cnt == 0) return 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second.first;
		int day = q.front().second.second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dir[i].first.first;
			int ny = y + dir[i].first.second;
			int nz = z + dir[i].second;
			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h) {
				if (visit[nz][nx][ny] == 0 && arr[nz][nx][ny] != -1) {
					q.push({ {nx,ny}, {nz,day + 1} });
					visit[nz][nx][ny] = 1;
					cnt -= 1;
					ans = day + 1;
					if (cnt == 0) break;
				}
			}
		}
	}
	if (cnt == 0) return ans;
	else return -1;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 1) {
					q.push({ { i,j }, { k,0 } });
					visit[k][i][j] = 1;
				}
				else if (arr[k][i][j] == 0) cnt++;//안익은 토마토 수
			}
		}
	}
	cout << tomato() << '\n';
	return 0;
}