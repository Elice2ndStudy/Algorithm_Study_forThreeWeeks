#include<iostream>
using namespace std;
int n, arr[65][65];
int ans[3];
void sol(int d, int r, int cnt) {
	int num = arr[d][r];
	int chk = -1;
	for (int i = d; i < d + cnt; i++) {
		for (int j = r; j < r + cnt; j++) {
			if (num != arr[i][j]) {
				chk = 1;
			}
		}
	}
	if (chk == -1) {
		cout << num;
		return;
	}
	int div = cnt / 2;
	cout << "(";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			
			sol(d + div * i, r + div * j, div);
			
		}
	}
	cout << ")";
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			 scanf("%1d",&arr[i][j]);
		}
	}
	sol(0, 0, n);
	cout << "\n";
}