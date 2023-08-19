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
	cin >> h >> w;
	vector<string> s(h);
	vector<vector<long long>> cnth(h, vector<long long>(26)), cntw(w, vector<long long>(26));
	rep(i, h) {
		cin >> s[i];
		rep(j, w) {
			cnth[i][s[i][j] - 'a']++;
			cntw[j][s[i][j] - 'a']++;
		}
	}
	set<long long> sth, stw;
	rep(i, h) {
		sth.insert(i);
	}
	rep(j, w) {
		stw.insert(j);
	}
	queue<long long> quh, quw;

	do {
		jud = 0;
		rep(i, h) {
			rep(k, 26) {
				if (cnth[i][k] == stw.size() && stw.size() >= 2) {
					jud = 1;
					quh.push(i);
				}
			}
		}
		rep(j, w) {
			rep(k, 26) {
				if (cntw[j][k] == sth.size() && sth.size() >= 2) {
					jud = 1;
					quw.push(j);
				}
			}
		}
		while (quh.size()) {
			i = quh.front();
			quh.pop();
			rep(k, 26) {
				cnth[i][k] = 0;
			}
			for (auto j : stw) {
				cntw[j][s[i][j] - 'a']--;
			}
			sth.erase(i);
		}
		while (quw.size()) {
			j = quw.front();
			quw.pop();
			rep(k, 26) {
				cntw[j][k] = 0;
			}
			for (auto i : sth) {
				cnth[i][s[i][j] - 'a']--;
			}
			stw.erase(j);
		}

	} while (jud);
	ans = sth.size() * stw.size();
	cout << ans << endl;

}