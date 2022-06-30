#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k, m, ans = 1e9;
vector <int> lion;
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> m;
        if(m == 1) lion.push_back(i);
    }
    for(int i = 0; i <= lion.size()- k; i++){
        ans = min(ans, lion[i + k - 1] - lion[i] + 1);
    }

    if(ans == 1e9) cout << -1 <<"\n";
    else cout << ans <<"\n";
}