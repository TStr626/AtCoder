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
	vector<long long> a(n), b(m);
	rep(i, n) {
		cin >> a[i];
	}
	rep(j, m) {
		cin >> b[j];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long ok = 1000000001, ng = -1, mid;
	auto itr1 = a.begin();
	auto itr2 = b.begin();
	while (ok - ng > 1) {
		mid = (ok + ng) / 2;
		cur = upper_bound(a.begin(), a.end(), mid)-a.begin();
		res = b.end() - lower_bound(b.begin(), b.end(), mid);
		//cout << mid << ' ' << cur << ' ' << res << endl;
		if (cur >= res) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	cout << ok << endl;
}