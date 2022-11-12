#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	
	map<long long,vector<long long>> mp;
	rep(i, n) {
		cin >> x >> y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	set<long long> checked;
	queue<long long> qu;
	ans = 1;
	qu.push(1); checked.insert(1);
	while (qu.size()) {
		cur = qu.front();
		qu.pop();
		ans = max(ans, cur);

		rep(j, mp[cur].size()) {
			res = mp[cur][j];
			if (checked.count(res)) {
				continue;
			}
			qu.push(res);
			checked.insert(res);
		}
	}
	cout << ans << endl;
	
}