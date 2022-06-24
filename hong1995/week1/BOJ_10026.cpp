#include<iostream>
#include<string.h>
#include<string>
using namespace std;
string board[105];
int chk[105][105];
int dr[4] = { 0, 0, 1,-1 }, dc[4] = { 1, -1,  0, 0 };
int n, cnt1, cnt2;
void dfs(int r, int c, char b) {
	chk[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
		if (!chk[nr][nc] && board[nr][nc] == b ) dfs(nr, nc, b);
	}
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!chk[i][j]) {
				dfs(i, j, board[i][j]);
				cnt1++;
			}
		}
	}
	cout << cnt1 << "\n";
	for (int i=0; i<n; i++)
		memset(chk, 0, sizeof(chk));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			if (board[i][j] == 'R') board[i][j] = 'G';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!chk[i][j]) {
				dfs(i, j, board[i][j]);
				cnt2++;
			}
		}
	}
	cout << cnt2 <<"\n";
}