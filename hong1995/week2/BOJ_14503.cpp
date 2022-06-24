#include <iostream>
using namespace std;
int board[52][52];
int chk[52][52];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int sum = 0;
int N, M, r, c, d;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> board[i][j];
	while (1) {
		if (chk[r][c] == 0) {		
			chk[r][c] = 1;
			sum++;
		}
		bool check = false;
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;
			int nx = r + dx[d];
			int ny = c + dy[d];
			if (board[nx][ny] == 0 && chk[nx][ny] == 0) {
				r += dx[d];
				c += dy[d];
				check = true;
				break;
			}
		}
		if (!check) { 
			int back = (d + 2) % 4;
			if (board[r + dx[back]][c + dy[back]] == 1) break;
			r += dx[back];
			c += dy[back];
		}
	}
	cout << sum << "\n";
}