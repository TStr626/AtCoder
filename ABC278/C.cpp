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
	long long query, t, a, b;
	cin >> n >> query;
	
	map<long long, set<long long>> mp;
	while (query--) {
		cin >> t >> a >> b;
		if (t == 1) {
			// add
			mp[a].insert(b);
		}
		if (t == 2) {
			// rem
			mp[a].erase(b);
		}
		if (t == 3) {
			// query
			if (mp[a].count(b) && mp[b].count(a)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	
}