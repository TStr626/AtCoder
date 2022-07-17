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

int main() {
	long long n, m, i, j, k, h, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;

	vector<pair<long long, long long>> p(n);
	vector<vector<long long>> lef(m, vector<long long>(0));
	vector<long long> ansv(m + 1, 0);
	rep(i, n) {
		cin >> p[i].first >> p[i].second;
		p[i].first--; p[i].second--;
		lef[p[i].second].push_back(p[i].first);
	}
	sort(p.begin(), p.end());

	cur = p[n - 1].first;
	multiset<long long> ms;
	auto itr = ms.begin();
	rep(i, n) {
		if (p[i].second < cur) {
			ms.insert(p[i].second);
		}
		else {
			ms.insert(p[i].first);
		}
	}

	for (cur = p[n - 1].first; cur <= m - 1; cur++) {
		rep(i, lef[cur].size()) {
			res = lef[cur][i];
			itr = ms.find(res);
			ms.erase(itr);
			ms.insert(cur);
		}

		itr = ms.begin();
		res = *itr;
		ansv[cur - res]++;
		ansv[cur + 1]--;
	}

	rep(i, m) {
		ansv[i + 1] += ansv[i];
		if (i) cout << ' ';
		cout << ansv[i];
	}
	cout << endl;



	
}