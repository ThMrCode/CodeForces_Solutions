#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
 
#define ll long long
const ll NP = 1000000000000;
 
int main() {
	int t; cin >> t;
	vector<int> solves;
	while (t--) {
		int m; cin >> m; ll x; cin >> x;
		vector<ll> c; vector <ll> h;
		c.resize(m); h.resize(m);
		ll h_max = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> c[i]; cin >> h[i];
			h_max += h[i];
		}
		// Estados de feliciad desde 0 hasta h_max
		vector<ll> dp = vector<ll>((h_max + 1), NP);
		dp[0] = 0;
		for (int i = 0; i < m; i++)
		{
			vector<ll> ndp = dp;
			for (int j = 0; j <= h_max; j++)
			{
				if (dp[j] == NP) continue;
				ll new_h = j + h[i];
				ll new_cost = dp[j] + c[i];
				if (new_cost <= (i * x) && new_cost < dp[new_h]) ndp[new_h] = new_cost;
			}
			dp = ndp;
		}
		for (int i = (dp.size()-1); i >= 0; i--)
		{
			if(dp[i] != NP ) { 
				solves.push_back(i);
				break;
			}
		}
	}
	for (int i = 0; i < solves.size(); i++)
	{
		cout << solves[i] << endl;
	}
	return 0;
}