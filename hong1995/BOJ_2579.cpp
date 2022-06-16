#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, st[305], dp[305];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>st[i];
    }
    dp[1] = st[1];
    dp[2] = st[1] + st[2];
    dp[3] = max((st[1] + st[3]), (st[2] + st[3]));
    for(int i=4; i<=n; i++){
        dp[i] = max((st[i-1] + dp[i-3]+st[i]), (dp[i-2]+st[i]));
    }
    cout << dp[n] <<"\n";
}