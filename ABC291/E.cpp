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
void yes() {
	cout << "Yes" << endl;
}
void no() {
	cout << "No" << endl;
}
void vec_h(vector<long long> a) {
	int n = a.size(), i;
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}
void vec_v(vector<long long> a) {
	for (auto c : a) {
		cout << c << endl;
	}
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<vector<long long>> g(n);
	vector<long long> din(n, 0);
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		g[y].push_back(x);
		din[x]++;
	}
	set<long long> st;
	rep(i, n) {
		if (din[i] == 0) {
			st.insert(i);
		}
	}
	k = n;
	vector<long long> vans(n);
	while (k--) {
		if (st.size() > 1) {
			no();
			return 0;
		}
		x = *st.begin();
		st.erase(x);
		vans[x] = k;
		for (auto y : g[x]) {
			din[y]--;
			if (din[y] == 0) {
				st.insert(y);
			}
		}
	}
	yes();
	rep(i, n) {
		if (i) cout << ' ';
		cout << vans[i] + 1;
	}
	cout << endl;
}