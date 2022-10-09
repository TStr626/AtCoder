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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 100000000;
	cin >> n >> m >> k;
	long long u, v;
	vector<vector<long long>> g(n, vector<long long>(0));
	rep(i, m) {
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<long long> a(n), b(k);
	rep(i, n) {
		cin >> a[i];
	}
	rep(j, k) {
		cin >> b[j];
	}

	deque<long long> deq;
	vector<long long> d(n, inf);
	deq.push_front(0);
	if (a[0] == b[0]) {
		d[0] = 1;
	}
	else {
		d[0] = 0;
	}
	
	while (!deq.empty()) {
		cur = deq.front();
		deq.pop_front();
		rep(j, g[cur].size()) {
			res = g[cur][j];

			if (d[cur] < k && a[res] == b[d[cur]]) {
				jud = d[cur] + 1;
				if (jud < d[res]) {
					d[res] = jud;
					deq.push_back(res);
				}
			}
			else {
				jud = d[cur];
				if (jud < d[res]) {
					d[res] = jud;
					deq.push_front(res);
				}
			}
			
		}
	}
	/*
	rep(i, n) {
		cout << d[i] << endl;
	}
	*/
	if (d[n - 1] == k) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}