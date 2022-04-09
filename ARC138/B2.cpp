#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

// experiment what a[i] can construct
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long b;
	cin >> n;
	vector<set<int>> st(n + 1);
	b = 1;
	st[0].insert(0);
	
	auto itr = st[0].begin();
	rep(i, n) {
		itr = st[i].begin();
		rep(j, st[i].size()) {
			cur = *itr;
			st[i + 1].insert(cur * 2);
			st[i + 1].insert(b - cur);
			itr++;
		}
		b = b * 2 + 1;
	}
	
	rep(i, n) {
		itr = st[i+1].begin();
		rep(j, st[i + 1].size()) {
			cout << *itr << ' ';
			itr++;
		}
		cout << endl;
	}
}