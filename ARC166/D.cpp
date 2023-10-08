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

struct blace {
	long long pos;
	long long cnt;
};
int main() {
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod, inf = 2000000000;
	cin >> n;
	vector<long long> x(n), y(n);
	rep(i, n) {
		cin >> x[i];
	}
	rep(i, n) {
		cin >> y[i];
	}
	deque<blace> ql, qr;
	ql.push_back({ -inf,y[0] });
	for (i = 1; i < n; i++) {
		if (y[i - 1] < y[i]) {
			ql.push_back({ x[i - 1] + 1,y[i] - y[i - 1] });
		}
		else if (y[i - 1] > y[i]) {
			qr.push_back({ x[i] - 1, y[i - 1] - y[i] });
		}
	}
	qr.push_back({ inf,y[n - 1] });
	blace bl, br;
	ans = 1000000000;
	while (ql.size()) {
		bl = ql.front();
		ql.pop_front();
		br = qr.front();
		qr.pop_front();
		ans = min(ans, br.pos - bl.pos);
		cur = min(bl.cnt, br.cnt);
		bl.cnt -= cur;
		br.cnt -= cur;
		if (bl.cnt > 0) {
			ql.push_front(bl);
		}
		if (br.cnt > 0) {
			qr.push_front(br);
		}
	}
	if (ans == 1000000000) {
		ans = -1;
	}
	cout << ans << endl;
}