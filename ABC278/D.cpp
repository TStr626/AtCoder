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

struct command {
	long long time;
	long long val;
};
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long query, t;
	cin >> n;
	vector<long long> a(n), time(n, -1);
	rep(i, n) {
		cin >> a[i];
	}
	cin >> query;

	map<int, queue<command>> qu;
	command as = { -2,0 };
	rep(k, query) {
		cin >> t;
		if (t == 1) {
			// assign
			cin >> x;
			as.time = k;
			as.val = x;
		}
		if (t == 2) {
			// add
			cin >> i >> x;
			i--;
			qu[i].push({ k,x });
		}
		if (t == 3) {
			// query
			cin >> i;
			i--;
			if (time[i] < as.time) {
				time[i] = as.time;
				a[i] = as.val;
			}
			while (qu[i].size()) {
				if (time[i] > qu[i].front().time) {
					// nope
				}
				else {
					time[i] = qu[i].front().time;
					a[i] += qu[i].front().val;
				}
				qu[i].pop();
			}
			cout << a[i] << endl;
		}
	}
}