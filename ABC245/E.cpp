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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	vector<pair<int, int>> pa(n), pc(m);

	rep(i, n) {
		cin >> pa[i].first;
		pa[i].first *= -1;
	}
	rep(i, n) {
		cin >> pa[i].second;
	}
	rep(j, m) {
		cin >> pc[j].first;
		pc[j].first *= -1;
	}
	rep(j, m) {
		cin >> pc[j].second;
	}

	sort(pa.begin(), pa.end());
	sort(pc.begin(), pc.end());
	multiset<int> st;
	j = 0;
	auto itr = st.begin();
	rep(i, n) {
		while (j < m && (pc[j].first <= pa[i].first)) {
			st.insert(pc[j].second);
			j++;
		}
		itr = st.lower_bound(pa[i].second);
		if (itr == st.end()) {
			cout << "No" << endl;
			return 0;
		}
		else {
			st.erase(itr);
		}
	}
	cout << "Yes" << endl;

}