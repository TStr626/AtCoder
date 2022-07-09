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

struct num {
	long long p;
	long long e;
};
struct info {
	long long e;
	long long i;
	bool isSolo;
};

int main() {
	long long n, m, i, j, k, h, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<vector<num>> t(n, vector<num>(0));
	vector<info> cnt(0);
	map<long long, long long> ptoi;
	cur = 1;
	info f;
	rep(i, n) {
		cin >> m;
		t[i].resize(m);
		rep(j, m) {
			cin >> t[i][j].p >> t[i][j].e;
			if (ptoi[t[i][j].p] == 0) {
				ptoi[t[i][j].p] = cur;
				cur++;
				cnt.push_back({ 0,0,false });
			}
			
			f.e = t[i][j].e;
			f.i = i;

			res = cnt[ptoi[t[i][j].p] - 1].e;
			if (res == f.e) {
				cnt[ptoi[t[i][j].p] - 1].isSolo = false;
			}
			else if (res < f.e) {
				cnt[ptoi[t[i][j].p] - 1].isSolo = true;
				cnt[ptoi[t[i][j].p] - 1].i = i;
				cnt[ptoi[t[i][j].p] - 1].e = f.e;
			}
		}
	}

	set<long long> st;
	rep(i, cnt.size()) {
		if (cnt[i].isSolo == true) {
			st.insert(cnt[i].i);
		}
	}
	ans = st.size() + 1;
	ans = min(ans, n);
	cout << ans << endl;
}