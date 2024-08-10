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
	map<int, int> mp;
	cin >> n;
	ans = 0;
	while (n--) {
		cin >> i;
		if (i == 1) {
			cin >> x;
			if (mp[x] == 0) {
				ans++;
			}
			mp[x]++;
		}
		else if (i == 2) {
			cin >> x;
			if (mp[x] == 1) {
				ans--;
			}
			mp[x]--;
		}
		else {
			cout << ans << endl;
		}
	}
}