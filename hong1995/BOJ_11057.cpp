#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, sum;
long long dp[1000];
long long add[11];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 10; i++) {
		add[i] = 1 % 10007;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			add[j] = (add[j] % 10007 + add[j - 1] % 10007) % 10007;
		}
		dp[i] = add[10] % 10007;
	}
	printf("%lld\n", dp[n] % 10007);
}
