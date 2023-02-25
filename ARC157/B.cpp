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
	cin >> n >> k;
	string s;
	cin >> s;
	multiset<long long> stx, sty;
	vector<long long> a(n, 0);
	vector<bool> checked(n, false);
	ans = 0;  cur = 0;
	rep(i, n) {
		if (i > 0 && s[i] == 'Y' && s[i - 1] == 'Y') {
			ans++;
		}
		if (s[i] == 'X') {
			cur++;
		}
	}
	if (cur >= k) {
		// 'X' to 'Y'
		jud = false;
		res = 0;
		rep(i, n) {
			if (s[i]=='Y') {
				if (jud && (res > 0)) {
					stx.insert(res);
					res = 0;
				}
				if (jud == false) {
					jud = true;
					res = 0;
				}
			}
			else {
				res++;
			}
		}
		while (k > 0 && stx.size()) {
			res = *stx.begin();
			if (res > k) {
				break;
			}
			k -= res;
			ans += res + 1;
			stx.erase(stx.begin());
		}
		if (k > 0) {
			ans += k;
		}
		if (jud == false) {
			ans = max(0ll, ans - 1);
		}
	}
	else {
		// 'Y' to 'X'
		ans = n - 1;
		k = k - cur;
		//cout << k << endl;
		jud = false;
		res = 0;
		rep(i, n) {
			if (s[i] == 'X') {
				if (jud && res > 0) {
					sty.insert(-res);
					res = 0;
				}
				if (jud == false) {
					jud = true;
					res = 0;
				}
			}
			else {
				if (jud == false && k>0) {
					k--;
					ans--;
				}
				if (jud == true) {
					res++;
				}
			}
		}
		ans -= min(k, res);
		k -= min(k, res);
		while (k > 0 && sty.size()) {
			res = -*sty.begin();
			ans -= min(k, res) + 1;
			k -= res;
			sty.erase(sty.begin());
		}
		ans = max(0ll, ans);
	}
	
	cout << ans << endl;
	
}