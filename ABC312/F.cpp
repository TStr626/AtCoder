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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	cur = 0;
	multiset<long long> ms;
	vector<long long> cl, op;
	rep(i, n) {
		cin >> k >> x;
		if (k == 0) {
			ms.insert(x);
			cur += x;
		}
		if (k == 1) {
			cl.push_back(x);
		}
		if (k == 2) {
			op.push_back(x);
		}
	}
	sort(cl.begin(), cl.end());
	sort(op.begin(), op.end());
	while (ms.size() > m) {
		cur -= *ms.begin();
		ms.erase(ms.begin());
	}
	ans = cur;
	while (m > 1 && op.size()) {
		// add opener
		m--;
		x = *op.rbegin();
		op.pop_back();
		while (x && cl.size()) {
			res = *cl.rbegin();
			ms.insert(res);
			cur += res;
			cl.pop_back();
			x--;
		}
		while (m < ms.size()) {
			cur -= *ms.begin();
			ms.erase(ms.begin());
		}
		ans = max(cur, ans);
	}
	cout << ans << endl;
}