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
	cin >> n;
	vector<long long> cnt(n, 0);
	for (i = 1; i < n; i++) {
		for (j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				cnt[i]++;
				if (j * j < i) {
					cnt[i]++;
				}
			}
		}
	}
	ans = 0;
	for (i = 1; i < n; i++) {
		j = n - i;
		ans += cnt[i] * cnt[j];
	}
	cout << ans << endl;
}