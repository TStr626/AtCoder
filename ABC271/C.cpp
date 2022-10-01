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
	long long n, m, i, j, k, x, y, h, w, ans, cur, res, jud, mod, inf;
	cin >> n;
	set<long long> st;
	ans = 0; cur = 0;
	rep(i, n) {
		cin >> x;
		if (st.count(x)) {
			cur++;
		}
		else {
			st.insert(x);
		}
	}

	auto itr = st.begin();
	while (true) {
		if (st.count(ans + 1)) {
			ans++;
			st.erase(ans);
		}
		else if (cur >= 2) {
			ans++;
			cur -= 2;
		}
		else if (cur == 1 && st.size() >= 1) {
			ans++;
			itr = st.end();
			itr--;
			st.erase(itr);
			cur -= 1;
		}
		else if (st.size() >= 2) {
			ans++;
			itr = st.end();
			itr--;
			st.erase(itr);
			itr = st.end();
			itr--;
			st.erase(itr);
		}
		else {
			break;
		}
	}
	cout << ans << endl;
}