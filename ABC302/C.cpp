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
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}
	vector<long long> p(n);
	rep(i, n) {
		p[i] = i;
	}

	do {
		rep(i, n - 1) {
			cur = 0;
			rep(j, m) {
				if (s[p[i]][j] != s[p[i + 1]][j]) {
					cur++;
				}
			}
			if (cur >= 2) {
				break;
			}
		}
		if (i == n - 1) {
			yes();
			return 0;
		}
	} while (next_permutation(p.begin(), p.end()));
	no();
}