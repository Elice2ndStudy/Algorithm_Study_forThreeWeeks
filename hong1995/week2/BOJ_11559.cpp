#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1, 0,0 };
const int row = 12;
const int col = 6;
int ans;
char arr[row][col];
int vis[row][col];
int py_count;
void down() {
	for (int c = 0; c < col; c++) {
		for (int r = row - 1; r >= 0; r--) {
			if (arr[r][c] == '.') {
				for (int tr = r - 1; tr >= 0; tr--) {
					if (arr[tr][c] != '.') {
						arr[r][c] = arr[tr][c];
						arr[tr][c] = '.';
						break;
					}
				}
			}
		}
	}
}
int dfs(int r, int c, char RGB) {
	int ret = 0;
	if (arr[r][c] == RGB) ret = vis[r][c];
	else if (arr[r][c] != RGB) return ret = 0;
	for (int i = 0; i < 4; i++) {
		int tr = r + dr[i];
		int tc = c + dc[i];
		if (tr < 0 || row <= tr || tc < 0 || col <= tc) continue;
		if (vis[tr][tc]) continue;
		if (arr[tr][tc] != RGB) continue;
		vis[tr][tc] = ++py_count;
		ret = max(ret, dfs(tr, tc, RGB));
	}
	return ret;
}
void del_dfs(int r, int c, char RGB) {
	if (arr[r][c] == RGB) arr[r][c] = '.';
	else if (arr[r][c] != RGB) return;
	for (int i = 0; i < 4; i++) {
		int tr = r + dr[i];
		int tc = c + dc[i];
		if (tr < 0 || row <= tr || tc < 0 || col <= tc) continue;
		if (arr[tr][tc] != RGB) continue;
		del_dfs(tr, tc, RGB);
	}
}
int main() {
	for (int r = 0; r < row; r++) {
		scanf("%s", arr[r]);
	} 
	while (1) {
		int ret = 0;
		memset(vis, 0, sizeof(vis));
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				if (arr[r][c] == '.') continue;
				vis[r][c] = py_count = 1;
				ret = max(dfs(r, c, arr[r][c]), ret);
				if (py_count >= 4) del_dfs(r, c, arr[r][c]);
			}
		}
		if (ret < 4) break;
		down();
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}