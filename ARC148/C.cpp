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
	long long query;
	cin >> n >> query;
	vector<long long> p(n);
	p[0] = -1;
	rep(i, n - 1) {
		cin >> p[i + 1];
		p[i + 1]--;
	}
	vector<long long> d(n);
	rep(i, n - 1) {
		d[p[i + 1]]++;
	}

	while (query--) {
		cin >> m;
		vector<long long> v(m);
		map<long long, long long> mp;
		set<long long> st;
		auto itr = st.begin();
		rep(i, m) {
			cin >> v[i];
			v[i]--;
			st.insert(v[i]);
		}

		ans = 0;
		
		while (!st.empty()) {
			itr = st.end();
			itr--;
			cur = *itr;
			st.erase(itr);
			
			res = p[cur];
			if (st.count(res)) {
				mp[res]++;
			}
			else {
				ans++;
			}
			ans += (d[cur] - mp[cur]);
		}

		cout << ans << endl;
	}
}