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
// WA

# define rep(i,n) for(i=0; i<n; i++)

long long n, m;
vector<string> s, t;
vector<long long> p;
string x;
set<string> ts;
bool found;
void dfs(long long i, long long cnt) {
	long long j, c, cur;
	if (found) {
		return;
	}
	
	x += s[i];
	
	if (i == n - 1) {
		//cout << x << endl;
		if (x.size() < 3) {
			return;
		}
		auto itr = ts.find(x);
		if (itr == ts.end()) {
			found = true;
		}
	}
	else {
		for (c = 0; c <= cnt; c++) {
			rep(j, c + 1) {
				x.push_back('_');
			}
			dfs(i + 1, cnt - c);
			if (found) {
				return;
			}
			rep(j, c + 1) {
				x.pop_back();
			}
		}
	}
	if (found) {
		return;
	}
	else {
		for (j = 0; j < s[i].size(); j++) {
			x.pop_back();
		}
	}
	
	return;
}

int main() {
	long long i, j, k, h, w, y, ans, cur, res, jud, mod, inf;
	cin >> n >> m;
	x = "";
	s.resize(n);
	cur = 16;
	rep(i, n) {
		cin >> s[i];
		cur -= s[i].size();
	}
	cur -= (n - 1);

	t.resize(m);
	rep(j, m) {
		cin >> t[j];
		ts.insert(t[j]);
	}

	p.resize(n);
	rep(i, n) {
		p[i] = i;
	}

	found = false;
	do {
		dfs(0, cur);
	} while (!found && next_permutation(p.begin(), p.end()));
	
	if (found) {
		cout << x << endl;
	}
	else {
		cout << -1 << endl;
	}
}