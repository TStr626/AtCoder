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

struct edge {
	long long to;
	long long cost;
};

vector<long long> dijkstra(vector<vector<edge>> g, long long r) {
	// need "struct edge"
	// input graph g, vertexs are 0-indexed, do not include parallel edges
	// r is source
	// inf=2e18;
	long long n = g.size(), inf = 2000000000000000000, u, v, i, j;
	vector<long long> d(n, inf);
	d[r] = 0;
	set<pair<long long, long long>> s;
	pair<long long, long long> p;
	auto itr = s.begin();
	for (i = 0; i < n; i++) {
		p.first = d[i]; p.second = i;
		s.insert(p);
	}
	while (!s.empty()) {
		itr = s.begin();
		p = *itr;
		s.erase(p);
		u = p.second;
		for (j = 0; j < g[u].size(); j++) {
			v = g[u][j].to;
			if (d[u] + g[u][j].cost < d[v]) {
				s.erase({ d[v],v });
				d[v] = d[u] + g[u][j].cost;
				s.insert({ d[v],v });
			}
		}
	}
	return d;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	
	vector<vector<long long>> s(n);
	vector<vector<edge>> g(n + m);
	rep(i, n) {
		cin >> k;
		rep(j, k) {
			cin >> x;
			x--;
			s[i].push_back(x);
			g[i].push_back({ n + x,1 });
			g[n + x].push_back({ i,0 });
		}
	}
	auto d = dijkstra(g, n);
	if (d[n + m - 1] == 2000000000000000000) {
		ans = -1;
	}
	else {
		ans = d[n + m - 1] - 1;
	}
	cout << ans << endl;
}