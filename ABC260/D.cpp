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
	long long n, m, i, j, k, h, w, cur, res, jud, mod;
	cin >> n >> k;
	vector<long long> p(n), ans(n, -1), und(n, -1);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	set<pair<long long, long long>> pil;
	auto itr = pil.begin();
	pair<long long, long long> pa;

	
	rep(i, n) {
		if (k == 1) {
			ans[p[i]] = i + 1;
		}

		itr = pil.lower_bound({ p[i],-1 });
		if (itr == pil.end()) {
			pil.insert({ p[i],1 });
		}
		else {
			pa = *itr;
			pil.erase(itr);

			und[p[i]] = pa.first;
			pa.first = p[i];
			pa.second++;

			if (pa.second == k) {
				cur = p[i];
				while (cur != -1) {
					ans[cur] = i + 1;
					cur = und[cur];
				}
			}
			else {
				pil.insert(pa);
			}
		}
	}

	rep(i, n) {
		cout << ans[i] << endl;
	}
	
}