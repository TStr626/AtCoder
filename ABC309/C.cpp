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

struct med {
	long long a;
	long long b;
};
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> k;
	vector<med> vm(n);
	rep(i, n) {
		cin >> vm[i].a >> vm[i].b;
	}
	long long ok = 1000000001, ng = 0, mid;
	while (ok - ng > 1) {
		mid = (ok + ng) / 2;
		cur = 0;
		rep(i, n) {
			if (vm[i].a >= mid) {
				cur += vm[i].b;
			}
		}
		if (cur <= k) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	cout << ok << endl;
}