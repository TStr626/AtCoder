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
	cin >> h >> w;
	vector<string> s(h), t(h);
	rep(i, h) {
		cin >> s[i];
	}
	rep(i, h) {
		cin >> t[i];
	}

	multiset<string> mss, mst;
	string cs, ct;
	rep(j, w) {
		cs = "";
		rep(i, h) {
			cs += s[i][j];
		}
		mss.insert(cs);
		ct = "";
		rep(i, h) {
			ct += t[i][j];
		}
		mst.insert(ct);
	}
	auto itrs = mss.begin(), itrt = mst.begin();
	while (mss.size()) {
		itrs = mss.begin();
		itrt = mst.begin();
		if (*itrs != *itrt) {
			cout << "No" << endl;
			return 0;
		}
		mss.erase(itrs);
		mst.erase(itrt);
	}
	cout << "Yes" << endl;
}