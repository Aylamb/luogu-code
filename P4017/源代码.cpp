#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v[500005];
const int MOD = 80112002;
int in[500005], dp[500005];

int dfs(int u){
	if(dp[u])  return dp[u];
	if(v[u].empty())  return dp[u] = 1;
	for(int i : v[u])  dp[u] = (dp[u] + dfs(i)) % MOD;
	return dp[u];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	v[a].push_back(b);
    	in[b]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)          if(in[i] == 0) ans = (ans + dfs(i)) % MOD;
	cout << ans;
    return 0;
}
